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
	if (MS::kSuccess !=  processing_arg_list(argList))	return MS::kFailure;
	if (MS::kSuccess != get_obj_transform_node())		return MS::kFailure;
	if (MS::kSuccess != get_anim_layer_ctrl_node())		return MS::kFailure;
	if (MS::kSuccess != get_anim_layer_mfncurves(TRANSLATEALIASX))		return MS::kFailure;
	if (MS::kSuccess != get_anim_layer_mfncurves(TRANSLATEALIASY))		return MS::kFailure;
	if (MS::kSuccess != get_anim_layer_mfncurves(TRANSLATEALIASZ))		return MS::kFailure;
	if (MS::kSuccess != get_anim_layer_mfncurves(ROTATEALIAS))			return MS::kFailure;

	DEBUG_MSG_OUTPUT(" TEST OUTPUT OF ANIMLAYER CURVES: ");
	for (int i = 0; i < anim_layer_curves_input.size(); i++) {
		DEBUG_MSG_OUTPUT("string:");
		DEBUG_MSG_OUTPUT(anim_layer_curves_input[i].first.c_str());
		DEBUG_MSG_OUTPUT("anim curve name:");
		DEBUG_MSG_OUTPUT(MFnAnimCurve(anim_layer_curves_input[i].second).absoluteName());
	}
	if (MS::kSuccess != get_anim_layer_keyframes())								return MS::kFailure;
	auto timerange = get_operation_time_range();
	DEBUG_MSG_OUTPUT("-----detected operational time range-----------");
	DEBUG_MSG_OUTPUT(timerange.first);
	DEBUG_MSG_OUTPUT(timerange.second);
	if (MS::kSuccess != anim_layer_mute_attr(true))								return MS::kFailure;
	if (MS::kSuccess != get_baked_transform(timerange.first, timerange.second))	return MS::kFailure;
	if (MS::kSuccess != anim_layer_mute_attr(false))							return MS::kFailure;
	
	DEBUG_MSG_OUTPUT("-------------- BAKED KEYS ----------------");
	for (int i = 0; i < 6; i++) {
		DEBUG_MSG_OUTPUT(BakedTransformKeys[i].first.c_str());
		DEBUG_MSG_OUTPUT(BakedTransformKeys[i].second);
	};
	
	if (MS::kSuccess != generate_interpolation_for_curve (anim_layer_curves_input[0].first)) return MS::kFailure;
	DEBUG_MSG_OUTPUT("----------interpolated additive keyframe (fake output so far)-------------------");
	DEBUG_MSG_OUTPUT(interpolated_by_speed_keys[0]);


	//  TODO:  check how to store and identify only active animation layer curves using std:set <MFnAnimCurve>  
	// getting children of plug got from the animlayer
	//DEBUG_MSG_OUTPUT("num of children:");
	//DEBUG_MSG_OUTPUT(plugRotation.numChildren());
	//for (int i = 0; i < plugRotation.numChildren(); i++)
	//{
	//	DEBUG_MSG_OUTPUT(plugRotation.child(i).name());
	//}

			/*  some map operational examples:  testmap.insert(pair<int, int>(1, 40));
			 or std::map<char,int> mymap;  mymap.emplace('x',100);    mymap.find('x');
			 */

	return MS::kSuccess;
}

MStatus interpolationBySpeed::processing_arg_list (const MArgList& argList)
{
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

	argDB.getFlagArgument(SOURCEOBJFLAG, 0, argObjName);   
	argDB.getFlagArgument(LAYERNAMEFLAG, 0, argLayerName); 

	DEBUG_MSG_OUTPUT(argObjName);
	DEBUG_MSG_OUTPUT(argLayerName);

	return MS::kSuccess;
}
MStatus interpolationBySpeed::get_obj_transform_node()
{
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

	return MS::kSuccess;
}
MStatus interpolationBySpeed::get_anim_layer_ctrl_node()
{
	//------------- Getting anmation Layer Node --------------------------------------------
	MSelectionList selList;
	MStatus stat = MS::kSuccess;
	selList.clear();
	selList.add(argLayerName);
	stat = selList.getDependNode(0, nodeAnimLayerSettings);
	if (MS::kSuccess != stat)
	{
		cerr << "interpolationBySpeed.mll can't find animation layer with the name set as -l param";
		return stat.statusCode();
	}
	DEBUG_MSG_OUTPUT("DEBUG: anim layer node name = ");
	DEBUG_MSG_OUTPUT(MFnDependencyNode(nodeAnimLayerSettings).absoluteName());

	return MS::kSuccess;
}
MStatus interpolationBySpeed::get_anim_layer_mfncurves(std::string transform_root)
{
	//-------------- Getting stack animation Curves in the animation layer ---------------
	DEBUG_MSG_OUTPUT("-------------------------");
	DEBUG_MSG_OUTPUT("-------------------------");
	DEBUG_MSG_OUTPUT("DEBUG:  looking for animation curves...");
	MString strLayerRotationNode = argObjName + transform_root.c_str() + argLayerName;
	DEBUG_MSG_OUTPUT(strLayerRotationNode);
	MSelectionList selList;
	selList.clear();
	selList.add(strLayerRotationNode);
	MObject depNodeRotation;
	selList.getDependNode(0, depNodeRotation);
	// getting children of dependency node got from animlayer
	DEBUG_MSG_OUTPUT("-------------------------");
	MPlugArray animLayerPlugs;
	MFnDependencyNode(depNodeRotation).getConnections(animLayerPlugs);
	std::stack <MObject> foundAnimCurves;   // ALL FOUND VALID ANIMCURVES ARE STORED HERE
	MStatus curve_status;
	for (uint i = 0; i < animLayerPlugs.length(); i++)
	{
		DEBUG_MSG_OUTPUT("connection name:");
		DEBUG_MSG_OUTPUT(animLayerPlugs[i].name());
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
			DEBUG_MSG_OUTPUT("node belongs to:");
			MObject nodePlugOut = plugOut.node();
			DEBUG_MSG_OUTPUT(MFnDependencyNode(nodePlugOut).absoluteName());
			DEBUG_MSG_OUTPUT("anim curve status:");
			MFnAnimCurve tryCurve (nodePlugOut, &curve_status); //update curve_status if nodePlugOut is a valid MFnAnimCurve
			if (curve_status) foundAnimCurves.push(nodePlugOut);;
			DEBUG_MSG_OUTPUT(MFnAnimCurve(nodePlugOut, &curve_status).absoluteName());
			DEBUG_MSG_OUTPUT(curve_status);
		}
		DEBUG_MSG_OUTPUT("-------------------------");
	}
	// Dirty HAck:  EXTRACTING ONLY LAST 3 ANIMCURVES  (temp hack until I will find better way to select curves that belong to current animlayer)
	int DirtyHack = 1;
	if (transform_root == ROTATEALIAS) DirtyHack = 3;
	for (int i = 0; i < DirtyHack; i++)
	{
	// EXTRACTING ONLY LAST 3 ANIMCURVES  (temp hack until I will find better way to select curves that belong to current animlayer)
		std::string strCurveName = MFnAnimCurve(foundAnimCurves.top(), &curve_status).absoluteName().asChar();
		anim_layer_curves_input.push_back(std::make_pair(strCurveName, foundAnimCurves.top())); //std::pair<std::string, MObject>
		foundAnimCurves.pop();
	};


	return MS::kSuccess;
}
MStatus interpolationBySpeed::anim_layer_mute_attr(bool mute_value)
{
	DEBUG_MSG_OUTPUT("------------anim layer ctrl attribute--------------");
	MPlug muteAttrPlug = MFnDependencyNode(nodeAnimLayerSettings).findPlug("mute");
	muteAttrPlug.setDouble(mute_value);
	DEBUG_MSG_OUTPUT(muteAttrPlug.name());
	DEBUG_MSG_OUTPUT(double(mute_value));

	return MS::kSuccess;
}
MStatus interpolationBySpeed::get_baked_transform(double range_start, double range_end)
{
	MFnTransform bakedTransform(nodeTransform);
	MEulerRotation currentEulerRotation;
	MVector        currentPosition;
	bakedTransform.getRotation(currentEulerRotation);
	MAnimControl animControl;
	std::queue <double> keys;
	std::vector <std::string> baseTransformChannels = { "translateX", "translateY", "translateZ", "rotateX","rotateY","rotateZ" };
	for (int i = 0; i < baseTransformChannels.size(); i++)  BakedTransformKeys.push_back(std::pair<std::string, std::queue <double>>(baseTransformChannels[i], keys)) ;

	for (double i = range_start; i < range_end; i++)
	{
		animControl.setCurrentTime(MTime(i, MTIME_FPS));
		currentPosition=bakedTransform.getTranslation(MSpace::kTransform);
		bakedTransform.getRotation(currentEulerRotation);
		//init class data storage
		BakedTransformKeys[0].second.push(currentPosition[0]);
		BakedTransformKeys[1].second.push(currentPosition[1]);
		BakedTransformKeys[2].second.push(currentPosition[2]);
		BakedTransformKeys[3].second.push(currentEulerRotation.x * RADIANCECOEF);
		BakedTransformKeys[4].second.push(currentEulerRotation.y * RADIANCECOEF);
		BakedTransformKeys[5].second.push(currentEulerRotation.z * RADIANCECOEF);

	}
	animControl.setCurrentTime(MTime(range_start, MTIME_FPS));

	return MS::kSuccess;
}
MStatus interpolationBySpeed::get_anim_layer_keyframes()
{
	DEBUG_MSG_OUTPUT("-----------Number of Keyframes: ------------------");
	for (int i = 0; i < 6; i++)
	{
		DEBUG_MSG_OUTPUT(anim_layer_curves_input[i].first.c_str());
		MFnAnimCurve mFnAnimCurve_itter(anim_layer_curves_input[i].second);
		uint numKeys = mFnAnimCurve_itter.numKeys();
		DEBUG_MSG_OUTPUT(numKeys);

		std::deque<std::pair<double, double>> one_curve_keyframes;
		for (uint j=0;j<numKeys;j++)
		{
			MTime KeyframeTimeValue(0.0, MTIME_FPS);
			KeyframeTimeValue = mFnAnimCurve_itter.time(j);  //24fps vs 30fps problem might be here
			//KeyframeTimeValue.setUnit(MTIME_FPS);
			one_curve_keyframes.push_back(std::make_pair(KeyframeTimeValue.value(), (mFnAnimCurve_itter.value(j)*RADIANCECOEF)));		
		};
		anim_layer_curves_keys.push_back(one_curve_keyframes);
		DEBUG_MSG_OUTPUT("keyframes:");
		// technique to go through std::deque with itterators
		for (std::deque<std::pair<double, double>>::iterator itt = anim_layer_curves_keys[i].begin();
			itt != anim_layer_curves_keys[i].end(); ++itt)
		{
			DEBUG_MSG_OUTPUT("key:");
			DEBUG_MSG_OUTPUT(itt->first);
			DEBUG_MSG_OUTPUT(itt->second);
		}


	};


	return  MS::kSuccess;
}
std::pair<double,double> interpolationBySpeed::get_operation_time_range()
{
	std::set <double> border_keys;
	for (int i = 0; i < 6; i++)
	{
		border_keys.insert(anim_layer_curves_keys[i].cbegin()->first);
		border_keys.insert(std::prev(anim_layer_curves_keys[i].cend())->first);
	};
	double time_min = *border_keys.begin();
	double time_max = *std::prev(border_keys.end());
	return std::make_pair(time_min,time_max);
}
std::queue<double> interpolationBySpeed::process_interpolation_by_speed(std::queue<double>& transform_keys, std::pair<double, double>& interpolated_values, int range)
{
	// temp fake implementation:
	std::queue<double> out_keys;
	double tmp_difference_even_spread = (interpolated_values.second - interpolated_values.first)/range;
	for (int i = 0; i < range; i++)
	{
		out_keys.push(interpolated_values.first + (tmp_difference_even_spread * i));
	}

	return out_keys;
}
MStatus interpolationBySpeed::generate_interpolation_for_curve(std::string& curve_name)
{
	uint curve_index = 0;
	bool search_result = false;
	for (uint i = 0; i < 6; i++)
	{
		if (anim_layer_curves_input[i].first == curve_name)
		{
			curve_index = i;
			search_result = true;
		}
	}
	if (search_result)
	{
		std::queue<std::pair<double, double>> output_keys;

		MFnAnimCurve processing_curve (anim_layer_curves_input[curve_index].second);
		std::pair<double, double> first_add_key = anim_layer_curves_keys[curve_index].front();
		anim_layer_curves_keys[curve_index].pop_front();
		std::pair<double, double> next_add_key = anim_layer_curves_keys[curve_index].front();
		int range = int(next_add_key.first) - int(first_add_key.first);
		std::queue<double> part_of_baked_keys;
		for (int i = 0; i < range; i++)  // this part is a source of bugs when keyframes start not from the min time
		{
			part_of_baked_keys.push(BakedTransformKeys[curve_index].second.front());
			BakedTransformKeys[curve_index].second.pop();
		}
		std::queue<double> interpolated_values = process_interpolation_by_speed(part_of_baked_keys, std::make_pair(first_add_key.second, next_add_key.second), range);
		for (int i = 0; i < range; i++) 
		{
			output_keys.push(std::make_pair(double(int(first_add_key.first) + i), interpolated_values.front()));
			interpolated_values.pop();
		};
		interpolated_by_speed_keys.push_back(output_keys);

		return MStatus::kSuccess;
	}
	else
		DEBUG_MSG_OUTPUT("ERROR: NO ANIMATION CURVE WITH PROVIDED NAME IN generate_interpolation_for_curve() found");
		return MStatus::kFailure;
}