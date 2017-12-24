#include "FollowGround.hpp"
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MVector.h>

////////////////////////////////////////
// _addAttr_inMesh
////////////////////////////////////////
void cma::FollowGround::_addAttr_inMesh(void) {
	MStatus stat;
	MFnTypedAttribute inMesh_attr;

	inMesh = inMesh_attr.create("inMesh", "i", MFnData::kMesh, &stat);
	if (stat != MStatus::kSuccess) throw stat;

	inMesh_attr.setWritable(true);
	inMesh_attr.setReadable(false);
	inMesh_attr.setStorable(false);
	inMesh_attr.setConnectable(true);
	inMesh_attr.setInternal(false);
	inMesh_attr.setChannelBox(false);
	
	if((stat = addAttribute(inMesh)) != MStatus::kSuccess) throw stat;
	
	stat = attributeAffects(inMesh, outPoint);
    if ( stat != MS::kSuccess ) throw stat;
}


////////////////////////////////////////
// _addAttr_inVector
////////////////////////////////////////
void cma::FollowGround::_addAttr_inVector(void){
	MStatus stat;
	MFnNumericAttribute inVector_attr;
	inVector = inVector_attr.createPoint("rayVector", "ray", &stat);
	if (stat != MStatus::kSuccess) throw stat;

	inVector_attr.setWritable(true);
	inVector_attr.setReadable(false);
	inVector_attr.setStorable(false);
	inVector_attr.setConnectable(true);
	inVector_attr.setInternal(false);
	inVector_attr.setChannelBox(true);	
	inVector_attr.setDefault(1.0, 0.0, 0.0);

	if((stat = addAttribute(inVector)) != MStatus::kSuccess) throw stat;
	
	stat = attributeAffects(inVector, outPoint);
    if ( stat != MS::kSuccess ) throw stat;
}
