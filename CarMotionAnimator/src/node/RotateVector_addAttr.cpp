#include "RotateVector.hpp"
#include <array>
#include <string>

void cma::RotateVector::_addAttrs(void){
	MStatus stat;

    //Attributes
	MFnNumericAttribute inVector_attr;  //inVector
    MFnNumericAttribute outVector_attr; //outVector
    MFnNumericAttribute length_attr; //length
    //MFnNumericAttribute rotate_quaternion_attr; //rotate_quaternion
    std::array<MFnNumericAttribute *, 4> attrs{
        &inVector_attr, &outVector_attr, &length_attr, &rotate_quaternion_attr
    };    

    //create
    inVector = inVector_attr.createVector("inVector", "in", &stat);
	MStatusException::throwIfError(stat, "inVectorアトリビュートの生成に失敗しました", "RotateVector::_addAttrs");
    outVector = outVector_attr.createVector("outVector", "out", &stat);
	MStatusException::throwIfError(stat, "outVectorアトリビュートの生成に失敗しました", "RotateVector::_addAttrs");
    length = length_attr.create("length", "len", &stat);
	MStatusException::throwIfError(stat, "lengthアトリビュートの生成に失敗しました", "RotateVector::_addAttrs");
    rotate_quaternion = rotate_quaternion_attr.createVector("rotateQuaternion", "quat", &stat);
	MStatusException::throwIfError(stat, "rotateQuaternionアトリビュートの生成に失敗しました", "RotateVector::_addAttrs");

    for(auto p = attrs.begin(); p != attrs.end(); p++){
        std::string name((*p)->name);   //connection name
        if(name == "inVector" || name == "rotateQuaternion"){
            //input connection
	        rayVector_attr.setWritable(true);
	        rayVector_attr.setReadable(true);
	        rayVector_attr.setStorable(false);
	        rayVector_attr.setConnectable(true);
	        rayVector_attr.setInternal(false);
	        rayVector_attr.setChannelBox(true);	
        }
    }rayVector_attr.addToCategory("Ray Attribute");

	stat = addAttribute(rayVector);
	MStatusException::throwIfError(stat, "rayVectorアトリビュートの追加に失敗しました", "FollowGround::_addAttr_rayVector");

	stat = attributeAffects(rayVector, outPoint);
	MStatusException::throwIfError(stat, "rayVectorアトリビュートにおいて、アトリビュート影響の登録に失敗しました", "FollowGround::_addAttr_rayVector");
}
