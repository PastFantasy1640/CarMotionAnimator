#include "KeepDistanceNode.hpp"

#include "maya/MFnTypedAttribute.h"

const MTypeId cma::KeepDistanceNode::id(cma::KeepDistanceNode::kKeepDistanceNodeID);
MObject cma::KeepDistanceNode::inMesh;


/** �R���X�g���N�^
 */
cma::KeepDistanceNode::KeepDistanceNode() {}


/** �f�N�X�g���N�^
 */
cma::KeepDistanceNode::~KeepDistanceNode() {}


/** creator
 * �C���X�^���X�̐V�K�����֐�
 * @returns �V�����C���X�^���X
 */
void * cma::KeepDistanceNode::creator(void) {
	return new KeepDistanceNode;
}


/** initialize
 * �������֐�
 * @returns �X�e�[�^�X����
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
