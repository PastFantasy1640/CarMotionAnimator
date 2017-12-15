#include "CarMotionAnimator.hpp"
#include <vector>
#include <string>


//*** INCLUDE HEADERS ***

//#include "Hogehoge.hpp"

//***********************

namespace {
class CommandPair {
public:
	const MString command;
	void * (*creator)();
	CommandPair(const MString & command, void * (*creator)()) : command(command), creator(creator) {}
	virtual ~CommandPair() {}
private:
	CommandPair() = delete;
};

//*** �V�����R�}���h��ǉ�����ꏊ ***
std::vector<CommandPair> getCommands(void) {
	//�R�}���h�������ɒǉ�
	//CommandPair("�R�}���h��", [�N���G�C�^�[�֐��̃|�C���^]),
	return std::vector<CommandPair> {
		//CommandPair("Hogehoge", cma::Hogehoge::creator),
	};
}
};


/** initializePlugin
 * �v���O�C���̏������������s���Bmaya������R�[�������֐��B
 */
MStatus cma::initializePlugin(MObject _obj) {
	MFnPlugin plugin(_obj, "Autodesk", "2015 update2");

	//�R�}���h�̒ǉ�
	std::vector<CommandPair> cmd_pairs = getCommands();
	MStatus stat;
	for (auto p = cmd_pairs.begin(); p != cmd_pairs.end(); ++p) {
		stat = plugin.registerCommand(p->command, p->creator);
		if (!stat) {
			//�R�}���h�o�^���ɃG���[������
			stat.perror(std::string("An error occured during registering command : " + std::string(p->command.asChar())).c_str());
			break;
		}
	}

	//�ǂݍ��݊���
	std::cerr << "Finished to load CarMotionAnimator plug-in." << std::endl;
	std::cerr << "(c) 2017 S.Shirao  version 0.1" << std::endl;

#ifdef _DEBUG
	//�f�o�b�O���̂ݕW���o�͂��G���[�o�͂֐؂�ւ�
	std::cout.rdbuf(std::cerr.rdbuf());
	std::cout << "CarMotionAnimator is debug mode." << std::endl;
#endif

	return stat;
}


/** uninitializePlugin
 * �v���O�C���̃A�����[�h�������s���Bmaya������R�[�������֐��B
 */
MStatus cma::uninitializePlugin(MObject _obj) {
	MFnPlugin plugin(_obj);

	//�R�}���h�̓o�^����
	std::vector<CommandPair> cmd_pairs = getCommands();
	MStatus stat;
	for (auto p = cmd_pairs.begin(); p != cmd_pairs.end(); ++p) {
		stat = plugin.deregisterCommand(p->command);
		if (!stat) {
			//�R�}���h�o�^�������ɃG���[������
			stat.perror(std::string("An error occured during deregistering command : " + std::string(p->command.asChar())).c_str());
			break;
		}
	}
	
	return stat;
}