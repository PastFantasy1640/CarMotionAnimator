#include "FollowGround.hpp"
#include "exception/MStatusException.hpp"

const MTypeId cma::FollowGround::id(cma::FollowGround::kFollowGroundID);
MObject cma::FollowGround::inMesh;
MObject cma::FollowGround::rayVector;
MObject cma::FollowGround::rayPoint;
MObject cma::FollowGround::outPoint;

////////////////////////////////////////
// FollowGround
////////////////////////////////////////
cma::FollowGround::FollowGround() { std::cout << "constructor" << std::endl; }


////////////////////////////////////////
// ~FollowGround
////////////////////////////////////////
cma::FollowGround::~FollowGround() {std::cout << "destructor" << std::endl;}


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

	//アトリビュートの追加
	try {
		_addAttr_outPoint();
		_addAttr_inMesh();
		_addAttr_rayVector();
		_addAttr_rayPoint();
	}
	catch (const MStatusException & e) {
		std::cerr << e.toString() << std::endl;
		return e.stat;
	}
	
	return MStatus::kSuccess;
}


////////////////////////////////////////
// compute
////////////////////////////////////////
MStatus cma::FollowGround::compute(const MPlug & plug, MDataBlock & data) {
	MStatus ret;
	
	try {

		if (plug == this->outPoint) {
			MDataHandle ground, ray_from, ray_vector;
			_getInputValue(data, &ground, &ray_from, &ray_vector);

			_setOutputValue(data, 0.0, 0.0f, 0.0f);

			data.setClean(plug);
		}
	}
	catch (MStatusException e) {
		std::cerr << e.toString() << std::endl;
	}
	return MStatus::kSuccess;
}

void cma::FollowGround::_getInputValue(MDataBlock & data, MDataHandle * ground, MDataHandle * ray_from, MDataHandle * ray_vector) {
	MStatus ret;
	*ground = data.inputValue(inMesh, &ret);
	MStatusException::throwIfError(ret, "groundメッシュの取得に失敗", "cma::FollowGround::_getInputValue");
	*ray_from = data.inputValue(rayPoint, &ret);
	MStatusException::throwIfError(ret, "レイ始点の取得に失敗", "cma::FollowGround::_getInputValue");
	*ray_vector = data.inputValue(rayVector, &ret);
	MStatusException::throwIfError(ret, "レイベクトルの取得に失敗", "cma::FollowGround::_getInputValue");
}

void cma::FollowGround::_setOutputValue(MDataBlock & data, const float x, const float y, const float z) {
	MStatus ret;
	MDataHandle outputHandle = data.outputValue(outPoint, &ret);
	MStatusException::throwIfError(ret, "outPointの取得に失敗", "cma::FollowGround::_setOutputValue");	
	outputHandle.set(x,y,z);
}
