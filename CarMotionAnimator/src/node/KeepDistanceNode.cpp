#include "KeepDistanceNode.hpp"

const MTypeId cma::KeepDistanceNode::id(cma::KeepDistanceNode::kKeepDistanceNodeID);

cma::KeepDistanceNode::KeepDistanceNode() {}

cma::KeepDistanceNode::~KeepDistanceNode() {}

MStatus cma::KeepDistanceNode::compute(const MPlug & plug, MDataBlock & data) {
	return MStatus();
}

void * cma::KeepDistanceNode::creator(void) {
	return nullptr;
}

MStatus cma::KeepDistanceNode::initialize(void) {
	return MStatus();
}
