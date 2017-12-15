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

//*** 新しいコマンドを追加する場所 ***
std::vector<CommandPair> getCommands(void) {
	//コマンドをここに追加
	//CommandPair("コマンド名", [クリエイター関数のポインタ]),
	return std::vector<CommandPair> {
		//CommandPair("Hogehoge", cma::Hogehoge::creator),
	};
}
};


/** initializePlugin
 * プラグインの初期化処理を行う。maya側からコールされる関数。
 */
MStatus cma::initializePlugin(MObject _obj) {
	MFnPlugin plugin(_obj, "Autodesk", "2015 update2");

	//コマンドの追加
	std::vector<CommandPair> cmd_pairs = getCommands();
	MStatus stat;
	for (auto p = cmd_pairs.begin(); p != cmd_pairs.end(); ++p) {
		stat = plugin.registerCommand(p->command, p->creator);
		if (!stat) {
			//コマンド登録時にエラーが発生
			stat.perror(std::string("An error occured during registering command : " + std::string(p->command.asChar())).c_str());
			break;
		}
	}

	//読み込み完了
	std::cerr << "Finished to load CarMotionAnimator plug-in." << std::endl;
	std::cerr << "(c) 2017 S.Shirao  version 0.1" << std::endl;

#ifdef _DEBUG
	//デバッグ時のみ標準出力をエラー出力へ切り替え
	std::cout.rdbuf(std::cerr.rdbuf());
	std::cout << "CarMotionAnimator is debug mode." << std::endl;
#endif

	return stat;
}


/** uninitializePlugin
 * プラグインのアンロード処理を行う。maya側からコールされる関数。
 */
MStatus cma::uninitializePlugin(MObject _obj) {
	MFnPlugin plugin(_obj);

	//コマンドの登録解除
	std::vector<CommandPair> cmd_pairs = getCommands();
	MStatus stat;
	for (auto p = cmd_pairs.begin(); p != cmd_pairs.end(); ++p) {
		stat = plugin.deregisterCommand(p->command);
		if (!stat) {
			//コマンド登録解除時にエラーが発生
			stat.perror(std::string("An error occured during deregistering command : " + std::string(p->command.asChar())).c_str());
			break;
		}
	}
	
	return stat;
}