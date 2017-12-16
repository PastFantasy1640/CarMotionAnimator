#include "KeepDistanceNode.hpp"
#include <cmath>

const MTypeId cma::KeepDistanceNode::id(cma::KeepDistanceNode::kKeepDistanceNodeID);

cma::KeepDistanceNode::KeepDistanceNode() {}

cma::KeepDistanceNode::~KeepDistanceNode() {}

MStatus cma::KeepDistanceNode::compute(const MPlug & plug, MDataBlock & data) {
	MStatus returnStatus;
	if (plug == output) {
		MDataHandle inputData = data.inputValue(input, &returnStatus);
		if (returnStatus != MS::kSuccess) cerr << "ERROR getting data" << endl;
		else {
			float result = std::sin(inputData.asFloat());
			MDataHandle outputHandle = data.outputValue(output);
			outputHandle.set(result);
			data.setClean(plug);
		}
	}

	return MStatus();
}

void * cma::KeepDistanceNode::creator(void) {
	return new KeepDistanceNode;
}

MStatus cma::KeepDistanceNode::initialize(void) {
	MFnNumericAttribute nAttr;

	output = nAttr.create("output", "out", MFnNumericData::kFloat, 0.0);
	nAttr.setWritable(false);
    nAttr.setStorable(false);

	input = nAttr.create( "input", "in", MFnNumericData::kFloat, 0.0 );
    nAttr.setStorable(true);
	
	addAttribute(input);
	attributeAffects(input, output);
	addAttribute(output);
	
	return MStatus::kSuccess;
}
