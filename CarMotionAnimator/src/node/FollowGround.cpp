#include "FollowGround.hpp"

#include "maya/MFnTypedAttribute.h"

const MTypeId cma::FollowGround::id(cma::FollowGround::kFollowGroundID);
MObject cma::FollowGround::inMesh;


/** コンストラクタ
 */
cma::FollowGround::FollowGround() {}


/** デクストラクタ
 */
cma::FollowGround::~FollowGround() {}


/** creator
 * インスタンスの新規生成関数
 * @returns 新しいインスタンス
 */
void * cma::FollowGround::creator(void) {
	return new FollowGround;
}


/** initialize
 * 初期化関数
 * @returns ステータス結果
 */
MStatus cma::FollowGround::initialize(void) {
	MFnTypedAttribute inMesh_attr;
	MStatus stat;

	inMesh = inMesh_attr.create("inMesh", "i", MFnData::kMesh);
	inMesh_attr.setStorable(false);
	inMesh_attr.setReadable(false);
	//inMesh_attr.setHidden(true);
	inMesh_attr.setChannelBox(false);
	stat = addAttribute(inMesh);
	
	
	

	return MStatus::kSuccess;
}

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
