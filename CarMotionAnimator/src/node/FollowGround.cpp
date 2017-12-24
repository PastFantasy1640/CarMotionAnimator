#include "FollowGround.hpp"

const MTypeId cma::FollowGround::id(cma::FollowGround::kFollowGroundID);
MObject cma::FollowGround::inMesh;
MObject cma::FollowGround::inVector;
MObject cma::FollowGround::outPoint;

////////////////////////////////////////
// FollowGround
////////////////////////////////////////
cma::FollowGround::FollowGround() {}


////////////////////////////////////////
// ~FollowGround
////////////////////////////////////////
cma::FollowGround::~FollowGround() {}


////////////////////////////////////////
// creator
////////////////////////////////////////
void * cma::FollowGround::creator(void) {
	return new FollowGround;
}


////////////////////////////////////////
// initialize
////////////////////////////////////////
MStatus cma::FollowGround::initialize(void) {
	MStatus stat;

	//アトリビュートの追加
	_addAttr_inMesh();
	_addAttr_inVector();	

	return MStatus::kSuccess;
}


////////////////////////////////////////
// compute
////////////////////////////////////////
MStatus cma::FollowGround::compute(const MPlug & plug, MDataBlock & data) {

	if (plug == inMesh) {
		std::cout << "inmesh compute" << std::endl;
	}

	/*MStatus returnStatus;
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
	*/
	return MStatus::kSuccess;
}

