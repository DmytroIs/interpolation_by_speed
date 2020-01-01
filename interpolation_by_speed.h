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
//#include <maya/MFnAttribute.h>
//#include <maya/MStringArray.h>

#include <queue>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <string>


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
//#define RADIANCECOEF 57.295827908

#define ROTATEALIAS		"_rotate_"
#define TRANSLATEALIASX "_translateX_"
#define TRANSLATEALIASY "_translateY_"
#define TRANSLATEALIASZ "_translateZ_"

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
	MString argObjName;
	MString argLayerName;

	//	Maya nodes: 
	MObject nodeTransform;
	MObject nodeAnimLayerSettings;
	//MFnTransform nodeTransformBaseData;

	//	Animation Data:
	//std::queue <double> keys;
	//std::queue <MString> test2;
	//std::set <MString> rotanimcurves;


	MStatus initDataFromMaya(const MArgList& argList);

	void DEBUG_MSG_OUTPUT(const MString& msg) { MGlobal::displayInfo(msg); };
	void DEBUG_MSG_OUTPUT(const double&  msg) { MGlobal::displayInfo(std::to_string(msg).c_str()); };
	
};

