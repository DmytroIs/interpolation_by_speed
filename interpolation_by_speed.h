//
// Copyright (C) 
// Dmytro Ishchenko
// File: interpolationBySpeedCmd.h
//
// MEL Command: interpolationBySpeed
//
// Author: Maya Plug-in Wizard 2.0
//
#pragma once

#include <maya/MPxCommand.h>
#include <maya/MDagPath.h>
#include <maya/MDoubleArray.h>
#include <maya/MFnAnimCurve.h>
#include <maya/MFnTransform.h>
#include <maya/MEulerRotation.h>
#include <maya/MAnimControl.h>
#include <maya/MGlobal.h>
#include <maya/MArgDatabase.h>
#include <maya/MSyntax.h>
#include <maya/MFnDagNode.h>
#include <maya/MSelectionList.h>
#include <maya/MPlug.h>
#include <maya/MPlugArray.h>
#include <maya/MVector.h>
#include <maya/MTypes.h>
//#include <maya/MFnAttribute.h>
//#include <maya/MStringArray.h>

#include <queue>
#include <stack>
//#include <map>
#include <set>
//#include <deque>
#include <stdlib.h>
#include <time.h>
#include <string>
//#include <utility>


//- Forward declaration
class MArgList;

//- A convenience enum to keep track of which axis the user wanted to rotate around
//typedef enum AXIS {AXIS_X = 1, AXIS_Y = 2, AXIS_Z = 3};       // *********** TODO: change here

//- This are the long and short command names.
#define SOURCEOBJFLAG		"-obj"											 
#define SOURCEOBJLONGFLAG	"-object"										
#define LAYERNAMEFLAG		"-l"												
#define LAYERNAMELONGFLAG	"-layer"										

//#define ROTATIONVALUE 0.785398163							  
#define RADIANCECOEF 57.295827908

#define ROTATEALIAS		"_rotate_"
#define TRANSLATEALIASX "_translateX_"
#define TRANSLATEALIASY "_translateY_"
#define TRANSLATEALIASZ "_translateZ_"

#define MTIME_FPS MTime::k30FPS

// Command class declaration
class interpolationBySpeed : public MPxCommand
{

public:
	interpolationBySpeed() {}
	virtual ~interpolationBySpeed() {}
	//- This method should perform a command by setting up internal class data
	//- and then calling the redoIt method if undo is supported by the command.
	//- The actual action performed by the command should be done in the redoIt 
	//- method. This is a pure virtual method, and must be overridden in derived 
	//- classes.
	virtual MStatus doIt( const MArgList& );
	//- This method should do the actual work of the command based on the internal 
	//- class data only. Internal class data should be set in the doIt method.
	virtual MStatus redoIt();
	//- This method should undo the work done by the redoIt method based on the 
	//- internal class data only.
	virtual MStatus undoIt();
	//- This method is used to specify whether or not the command is undoable. In 
	//- the base class, it always returns false. If you are writing a command that 
	//- might be eligible for undo, you should override this method.
	//- After Maya executes the command's doIt method, it will call isUndoable. If 
	//- isUndoable returns true, Maya will retain the instance of the class and pass 
	//- it to Maya's undo manager so that the undoIt and redoIt methods can be called
	//- when appropriate. If isUndoable returns false, the command instance will be 
	//- immediately destroyed.
	virtual bool isUndoable() const {
		return true;
	}

	static void* creator() {
		return new interpolationBySpeed();
	}


	virtual	bool hasSyntax() {
		return true;
	}
	static MSyntax cmdSyntax();

	//- Rotates each instance with 45 degrees along user-specified axis
	void rotate( MDagPath dp );																 // *********** TODO:

	//- Store the user selection of the rotation axis (one axis for all of the instances)
//	AXIS axis;																				 // *********** TODO:

	/**///--------------DELETE DURING CLEAN UP--------------------------------------------------------------------------
	/**///	Store the base shape for the instances here for undo									 /**/
	/**/	MDagPath shapeObj;																		 /**/
	/**/	//- Store the number of instances for one shape											 /**/
	/**/	uint numInstances;																		 /**/
	/**/	//- Store the original rotation values for undo here									 /**/
	/**/	MDoubleArray rotations;																	 /**/
	/**/	//- storing curve																		 /**/
	/**/	MObject fCurve;																			 /**/
	/**///------------END OF DELETE SECTION------------------------------------------------------------------------------

public:
	//	DATA:
	//	Command Argument:
	MString argObjName; 																// user input arguments
	MString argLayerName;																// user input arguments
	//	Maya nodes: 																	//
	MObject nodeTransform;																// maya node with resulting transformation output of argObjName
	MObject nodeAnimLayerSettings;														// maya node that controls animlayer settings (mute attr incl)
	std::vector <std::pair <std::string, MObject>>			anim_layer_curves_input;	// names and MObj links to 6 animation curves in the animlayer
	//	Animation Data:																	//
	std::vector <std::deque <std::pair <double, double>>>	anim_layer_curves_keys;		// times and values of keyframes of 6 animation curves in the animlayer
	std::vector <std::pair <std::string, std::queue <double>>> BakedTransformKeys;		// names and values of baked tansfrom channels of 6 animations curve (before the update)
	std::vector <std::queue <std::pair <double, double>>>	interpolated_by_speed_keys;

	MStatus initDataFromMaya(const MArgList& argList);

	void DEBUG_MSG_OUTPUT(const MString& msg) const { MGlobal::displayInfo(msg); };
	void DEBUG_MSG_OUTPUT(const double&  msg) const { MGlobal::displayInfo(std::to_string(msg).c_str()); };
	void DEBUG_MSG_OUTPUT( std::queue<double> msg) const {
		std::string strout;
		for (int i = 0; i < msg.size(); i++) {
			strout.append(std::to_string (msg.front()));
			strout.append(" ");
			msg.pop();
		};
		MGlobal::displayInfo(strout.c_str());
	};
	void DEBUG_MSG_OUTPUT(const std::deque<std::pair<double,double>>& msg ) const 
	{
		std::string out_msg = "key: ";
		for (auto itt = msg.cbegin();
			itt != msg.cend();
			++itt)
		{
			out_msg += std::to_string(itt->first);
			out_msg += " - ";
			out_msg += std::to_string(itt->first);
			MGlobal::displayInfo(out_msg.c_str());
			out_msg = "key: ";
		}
	};
	void DEBUG_MSG_OUTPUT( std::queue<std::pair<double, double>> msg) 
	{
		std::string out_msg = "key: ";
		while (!msg.empty())
		{
			out_msg += std::to_string(msg.front().first);
			out_msg += " - ";
			out_msg += std::to_string(msg.front().second);
			MGlobal::displayInfo(out_msg.c_str());
			out_msg = "key: ";
			msg.pop();
		};
	}

private:
	MStatus processing_arg_list(const MArgList& argList);
	MStatus get_obj_transform_node();
	MStatus get_anim_layer_ctrl_node();
	MStatus get_anim_layer_mfncurves(std::string transform_root);
	MStatus anim_layer_mute_attr(bool mute_value);
	MStatus get_baked_transform (double range_start, double range_end) ;
	MStatus get_anim_layer_keyframes();
	std::pair<double, double> get_operation_time_range();
	MStatus generate_interpolation_for_curve(std::string& curve_name);

	std::queue<double> process_interpolation_by_speed(std::queue<double>& transform_keys, std::pair<double, double>& interpolated_values, int range);

};

