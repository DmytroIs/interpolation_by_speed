//
// Copyright (C) 
// 
// File: interpolationBySpeedCmd.cpp
//
// MEL Command: interpolationBySpeed
//
// Author: Maya Plug-in Wizard 2.0
//

#include "interpolation_by_speed.h"


//- Create a new MSyntax object to teach Maya about possible arguments
//- in our command. This newSyntax() method is used during the command
//- registration into our plug-in
/*static*/ MSyntax interpolationBySpeed::cmdSyntax()
{
	MSyntax syntax;
	syntax.addFlag(SOURCEOBJFLAG, SOURCEOBJLONGFLAG, MSyntax::kString); 				    // *********** TODO: 
	syntax.addFlag(LAYERNAMEFLAG, LAYERNAMELONGFLAG, MSyntax::kString); 						// *********** TODO: 
	syntax.enableEdit(false);
	syntax.enableQuery(false);
	return syntax;
}

//- This method should perform a command by setting up internal class data
//- and then calling the redoIt method if undo is supported by the command.
//- The actual action performed by the command should be done in the redoIt 
//- method. This is a pure virtual method, and must be overridden in derived 
//- classes.
MStatus interpolationBySpeed::doIt(const MArgList& argList)
{
	MStatus InitStatus = initDataFromMaya(argList);
	if (InitStatus == MS::kSuccess) {/*do good stuff here */}
	else {/*do bad stuff here */};
	
	
//	// test code to obtain shape object out of string1
//	MString arg1_str;
//	MString arg2_str;
//	MDagPath dagPath;
//	MSelectionList selList;
//	selList.add(arg1_str);
//	selList.getDagPath(0, dagPath);
//	dagPath.extendToShape();
//	MGlobal::displayInfo(dagPath.fullPathName().asChar());
//	// test code: gettign rotation and translation data
//	MGlobal::displayInfo("<interpolationBySpeed Message>: Debug info to get to animation keys:");
//	MFnDagNode dagNode(dagPath);
//	uint tempParentsCount = dagNode.parentCount();
//	for (uint i = 0; i < tempParentsCount; i++)
//	{
//
//		MObject currentParent = dagNode.parent(i);
//		MFnDependencyNode fnParent(currentParent);
//		MGlobal::displayInfo("<interpolationBySpeed Message>: ParentName: ");
//		MGlobal::displayInfo(fnParent.absoluteName());
//		MPlug rotPlug = fnParent.findPlug("rotate");
//		MGlobal::displayInfo("<interpolationBySpeed Message>: Rotate Plug name: ");
//		MGlobal::displayInfo(rotPlug.name());
//		MPlug rotxPlug = rotPlug.child(0);
//		MPlug rotyPlug = rotPlug.child(1);
//		MPlug rotzPlug = rotPlug.child(2);
//		MGlobal::displayInfo("<interpolationBySpeed Message>: Number Of children with 'Rotate': ");
//		MGlobal::displayInfo(std::to_string(rotPlug.numChildren()).c_str());
//		// getting tranform data, same as with MFnTranform but through MPlug component of rotation
//		double origRot = 0;
//		rotxPlug.getValue(origRot);
//		MGlobal::displayInfo("<interpolationBySpeed Message>: Data from MPlug::GetValue()  Rotation X = :");
//		MGlobal::displayInfo(std::to_string(origRot * RADIANCECOEF).c_str());
//		// getting data from animtion curve by active animation layer
//		MFnAnimCurve curve(rotxPlug);
//		double curveValue;
//		curve.evaluate(MTime(1.0, MTime::k30FPS), curveValue);   // TODO: add fps from settings
//		MGlobal::displayInfo("<interpolationBySpeed Message>: Data from MFnAnimCurve::evaluate()  Rotation X = :");
//		MGlobal::displayInfo(std::to_string(curveValue * RADIANCECOEF).c_str());
//		MGlobal::displayInfo(curve.name());
//		MGlobal::displayInfo(rotxPlug.name());
//
//	};
//
//	//  getting baked transform
//	MFnTransform bakedTransform(dagNode.parent(0));
//	MGlobal::displayInfo("<interpolationBySpeed Message>: Transform name:");
//	MGlobal::displayInfo(bakedTransform.name());
//	MEulerRotation currentEulerRotation;
//	bakedTransform.getRotation(currentEulerRotation);
//	MGlobal::displayInfo("<interpolationBySpeed Message>: Rotation Data:");
//	MGlobal::displayInfo(std::to_string(currentEulerRotation.x * RADIANCECOEF).c_str());
//	//  getting baked transform in time
//	MAnimControl animControl;
//	for (double i = 1; i < 30; i++)
//	{
//		animControl.setCurrentTime(MTime(i, MTime::k30FPS));
//		bakedTransform.getRotation(currentEulerRotation);
//		MGlobal::displayInfo("<interpolationBySpeed Message>: Rotation Data:");
//		MGlobal::displayInfo(std::to_string(currentEulerRotation.x * RADIANCECOEF).c_str());
//	}
//	animControl.setCurrentTime(MTime(1.0, MTime::k30FPS));
//
//	// turning off animation layers
//	MGlobal::displayInfo("<interpolationBySpeed Message>: AnimLayer Data:");
//	MSelectionList selList2;
//	selList2.add(arg2_str);
//	//MDagPath animLayerPath;
//	//selList2.getDagPath(0, animLayerPath);
//	//MGlobal::displayInfo(animLayerPath.fullPathName());
//	MPlug animLayerPlug;
//	selList2.getPlug(0, animLayerPlug);
//	MGlobal::displayInfo(animLayerPlug.name());
//	MGlobal::displayInfo(std::to_string(animLayerPlug.numChildren()).c_str());
//	MObject animLayerDepNodeObj;
//	selList2.getDependNode(0, animLayerDepNodeObj);
//	MFnDependencyNode animLayerDepNode = animLayerDepNodeObj;
//	MGlobal::displayInfo(animLayerDepNode.name());
//	//MGlobal::displayInfo("attr list: ");
//	//for (int i = 0; i < animLayerDepNode.attributeCount(); i++)
//	//{
//	//	MFnAttribute currAttr(animLayerDepNode.attribute(i));
//	//	MGlobal::displayInfo(currAttr.name());
//	//}
//	//MObject attrMuteObj;
//	//animLayerDepNode.findAlias("Mute", attrMuteObj);
//	//MFnAttribute FnAttrMute(attrMute);
//	//MPlug muteAttrPlug = animLayerDepNode.findPlug(attrMuteObj);
//	MPlug muteAttrPlug = animLayerDepNode.findPlug("mute");
//	MGlobal::displayInfo(muteAttrPlug.name());
//	muteAttrPlug.setDouble(1.0);
//	
//	// selecting curves in animation layer:  
//
//
//
//

	return redoIt();
}

//- This method should do the actual work of the command based on the internal 
//- class data only. Internal class data should be set in the doIt method.
MStatus interpolationBySpeed::redoIt()
{
//	setResult( "<interpolationBySpeed Message>: interpolationBySpeed command executed! \n" );
//
//	//- This is really where is the intelligence of the command. Here we will
//	//- preform all the actions we wanted to implement for this command.
//
//	//- Get the active selection in the Maya viewport.
//	MSelectionList selList;
//	MGlobal::getActiveSelectionList(selList);
//
//	if(selList.isEmpty())
//	{
//		MGlobal::displayError("<interpolationBySpeed Message>:  selList.isEmpty()==1");
//		return MS::kFailure;
//	}
//
//	MDagPath dagPath;
//	selList.getDagPath(0,dagPath);
//
//	//- Chances are the user selected the object from the panel view or
//	//- outliner window so the object in the list will actually be a 
//	//- transform node... if so we call extendToShape to grab the actual
//	//- shape node from the dagPath
//	if(dagPath.hasFn(MFn::kTransform))
//	{
//		dagPath.extendToShape();
//	}
//		
//
////	if(dagPath.isInstanced())
////	{
//		shapeObj = dagPath;
//		rotate(dagPath);
////	}
////	else
////	{
////		MGlobal::displayError("<interpolationBySpeed Message>:  dagPath.isInstanced()=false, full path: ");
////		MGlobal::displayError(dagPath.fullPathName().asChar());
////		return MS::kFailure;
////	}

	return MS::kSuccess;
}

//- This method should undo the work done by the redoIt method based on the 
//- internal class data only.
MStatus interpolationBySpeed::undoIt()
{
//	MGlobal::displayInfo( "<interpolationBySpeed Message>:  interpolationBySpeed command undone!\n" );
//	
//	MFnDagNode fnDag(shapeObj);
//
//	for(uint i = 0; i<numInstances; i++)
//	{
//
//		MObject currentParent = fnDag.parent(i);
//		MFnDependencyNode fnParent(currentParent);
//		MPlug rotPlug = fnParent.findPlug("rotate");
//		switch (axis)
//		{
//		case AXIS_X:
//			{
//				MPlug rotxPlug = rotPlug.child(0);
//				rotxPlug.setValue(rotations[i]);
//				break;
//			}
//		case AXIS_Y:
//			{
//				MPlug rotyPlug = rotPlug.child(1);
//				rotyPlug.setValue(rotations[i]);
//				break;
//			}
//		case AXIS_Z:
//			{
//				MPlug rotzPlug = rotPlug.child(2);
//				rotzPlug.setValue(rotations[i]);
//				break;
//			}
//		default:
//			{
//				MPlug rotyPlug = rotPlug.child(1);
//				rotyPlug.setValue(rotations[i]);
//				break;
//			}
//		}
//	}
//
//	//- Empty the array in case the user chooses redoIt
//	rotations.clear();

	return MS::kSuccess;
}

//- Method used by redoIt to assign a 45 degree rotation along a random axis.
void interpolationBySpeed::rotate( MDagPath dp )
{
//	//- Seeds the random number generation function rand so it does not produce the 
//	//- same sequence of numbers every time.
//	srand(time(NULL));
//
//	//- The passed-in dag object is a shape object, 
//	//- need to find all the parent transform objects.
//	MFnDagNode fnDag(dp);
//	//- The number of parents represents the current number of instances.
//	numInstances = fnDag.parentCount();
//
//	for(uint i = 0;i<numInstances;i++)
//	{
//		MObject currentParent = fnDag.parent(i);
//		MFnDependencyNode fnParent(currentParent);	
//
//		//- Find the rotate plug, figure out which axis the user opted for 
//		//- and set the plug to a random direction.
//		MPlug rotPlug = fnParent.findPlug("rotate");
//
//		//- Acquire a random number deciding which direction the 45 degree should be
//		int randVal;
//		if(rand()%2 == 0)
//			randVal = 1;
//		else randVal = -1;
//		cout<<"The randVal is "<<randVal<<endl;
//
//		switch(axis)
//		{
//
//		case AXIS_X:
//			{
//				MPlug rotxPlug = rotPlug.child(0);
//
//				//- retrieve original rotation and store it in member variable "rotations"
//				double origRot = 0;
//				rotxPlug.getValue(origRot);
//				rotations.append(origRot);
//
//				//- set new rotation
//				double rot = origRot + randVal * ROTATIONVALUE;
//				rotxPlug.setValue(rot);
//				break;
//			}
//		case AXIS_Y:
//		default: //- by default, rotate around y axis
//			{
//				MPlug rotyPlug = rotPlug.child(1);
//
//				double origRot = 0;
//				rotyPlug.getValue(origRot);
//				rotations.append(origRot);
//
//				double rot = origRot + randVal * ROTATIONVALUE;
//				rotyPlug.setValue(rot);
//				break;
//			}
//		case AXIS_Z:
//			{
//				MPlug rotzPlug = rotPlug.child(2);
//
//				double origRot = 0;
//				rotzPlug.getValue(origRot);
//				rotations.append(origRot);
//
//				double rot = origRot + randVal * ROTATIONVALUE;
//				rotzPlug.setValue(rot);
//				break;
//			}
//		}
//	}

}

MStatus interpolationBySpeed::initDataFromMaya(const MArgList& argList)
{
	// ---------Reading Command Arguments to Strings: --------------------------------------------
	MStatus stat = MS::kSuccess;
	MArgDatabase argDB(syntax(), argList, &stat);
	if (MS::kSuccess != stat)
	{
		cerr << "interpolationBySpeed.mll can't initialize its arguments according to its syntax";
		return stat.statusCode();
	}

	unsigned int numFlags = argDB.numberOfFlagsUsed();
	if (numFlags != 2)
	{
		MGlobal::displayError("interpolationBySpeed.mll: syntax error. two parameters are required: -obj as an object name and -l as an additive layer name");
		return MS::kFailure;
	}

	argDB.getFlagArgument(SOURCEOBJFLAG, 0, argObjName);   //to put here debug output msg
	argDB.getFlagArgument(LAYERNAMEFLAG, 0, argLayerName); //to put here debug output msg
	DEBUG_MSG_OUTPUT(argObjName);
	DEBUG_MSG_OUTPUT(argLayerName);

	//------------ Getting theTransform Node, named in first argument ------------------------------
	MDagPath dagPath;                 //it's so complicated, to handle the outliner window selection
	MSelectionList selList;
	selList.add(argObjName);
	selList.getDagPath(0, dagPath);
	dagPath.extendToShape();
	MFnDagNode dagNode(dagPath);  
	uint parentsCount = dagNode.parentCount();
	if (!parentsCount) {
		MGlobal::displayError("interpolationBySpeed.mll: no transfrom node found for the specified object");
		return MS::kFailure;
	};
	DEBUG_MSG_OUTPUT("DEBUG: parentCount() = ");
	DEBUG_MSG_OUTPUT(parentsCount);
	nodeTransform = dagNode.parent(0);
	DEBUG_MSG_OUTPUT("DEBUG: Object Transform Node Name =");
	DEBUG_MSG_OUTPUT(MFnDependencyNode(nodeTransform).absoluteName());

	//------------- Getting anmation Layer Node --------------------------------------------
	selList.clear();
	selList.add(argLayerName);
	stat = selList.getDependNode(0, nodeAnimLayerSettings);
	if (MS::kSuccess != stat)
	{
		cerr << "interpolationBySpeed.mll can't find animation layer with the name set as -l param";
		return stat.statusCode();
	}
	DEBUG_MSG_OUTPUT("DEBUG: anim layer node name = ");
	DEBUG_MSG_OUTPUT(MFnDependencyNode (nodeAnimLayerSettings).absoluteName());

	//-------------- Getting stack animation Curves in the animation layer ---------------
	DEBUG_MSG_OUTPUT("-------------------------");
	DEBUG_MSG_OUTPUT("-------------------------");
	DEBUG_MSG_OUTPUT("DEBUG:  looking for animation curves...");
	MString strLayerRotationNode = argObjName + ROTATEALIAS + argLayerName;
	DEBUG_MSG_OUTPUT(strLayerRotationNode);
	selList.clear();
	selList.add(strLayerRotationNode);
	MObject depNodeRotation;
	selList.getDependNode(0,depNodeRotation);

	// getting children of dependency node got from animlayer
	DEBUG_MSG_OUTPUT("-------------------------");
	MPlugArray animLayerPlugs;
	MFnDependencyNode(depNodeRotation).getConnections(animLayerPlugs);
	for (int i =0; i< animLayerPlugs.length(); i++)
	{ 
		DEBUG_MSG_OUTPUT("connection name:");
		DEBUG_MSG_OUTPUT(animLayerPlugs[i].name() );
		DEBUG_MSG_OUTPUT(" childrenNum()");
		DEBUG_MSG_OUTPUT(animLayerPlugs[i].numChildren());
		DEBUG_MSG_OUTPUT(" source or distanation:");
		DEBUG_MSG_OUTPUT(animLayerPlugs[i].isSource());
		DEBUG_MSG_OUTPUT(animLayerPlugs[i].isDestination());
		if (animLayerPlugs[i].isDestination())
		{
			DEBUG_MSG_OUTPUT("distanation plug name:");
			MPlug plugOut = animLayerPlugs[i].sourceWithConversion();
			DEBUG_MSG_OUTPUT(plugOut.name());
			DEBUG_MSG_OUTPUT("node it belongs to:");
			MObject nodePlugOut = plugOut.node();
			DEBUG_MSG_OUTPUT(MFnDependencyNode(nodePlugOut).absoluteName());
			DEBUG_MSG_OUTPUT("anim curve status:");
			MStatus stat2;
			DEBUG_MSG_OUTPUT(MFnAnimCurve(nodePlugOut, &stat2).absoluteName());
			DEBUG_MSG_OUTPUT(stat2);

		}
		DEBUG_MSG_OUTPUT("-------------------------");
		
	}

	// getting children of plug got from the animlayer
	//DEBUG_MSG_OUTPUT("num of children:");
	//DEBUG_MSG_OUTPUT(plugRotation.numChildren());
	//for (int i = 0; i < plugRotation.numChildren(); i++)
	//{
	//	DEBUG_MSG_OUTPUT(plugRotation.child(i).name());
	//}



	return MS::kSuccess;
}


