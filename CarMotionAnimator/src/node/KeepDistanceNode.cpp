#include "KeepDistanceNode.hpp"

#include "maya/MFnTypedAttribute.h"

const MTypeId cma::KeepDistanceNode::id(cma::KeepDistanceNode::kKeepDistanceNodeID);
MObject cma::KeepDistanceNode::inMesh;


/** コンストラクタ
 */
cma::KeepDistanceNode::KeepDistanceNode() {}


/** デクストラクタ
 */
cma::KeepDistanceNode::~KeepDistanceNode() {}


/** creator
 * インスタンスの新規生成関数
 * @returns 新しいインスタンス
 */
void * cma::KeepDistanceNode::creator(void) {
	return new KeepDistanceNode;
}


/** initialize
 * 初期化関数
 * @returns ステータス結果
 */
MStatus cma::KeepDistanceNode::initialize(void) {
	MFnTypedAttribute inMesh_attr;
	MStatus stat;

	inMesh = inMesh_attr.create("inMesh", "i", MFnData::kMesh);
	inMesh_attr.setStorable(false);
	inMesh_attr.setReadable(false);
	//inMesh_attr.setHidden(true);
	stat = addAttribute(inMesh);

	return MStatus::kSuccess;
}

MStatus cma::KeepDistanceNode::compute(const MPlug & plug, MDataBlock & data) {

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
