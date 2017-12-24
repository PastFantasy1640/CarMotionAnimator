/////////////////////////////////////////////////////
//MStatusException.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_MSTATUSEXCEPTION_HPP_
#define CMA_MSTATUSEXCEPTION_HPP_

#include <maya/MString.h>
#include <maya/MStatus.h>

namespace cma {

/** MStatusException CLASS
 * 説明
 */
class MStatusException{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	const MStatus stat;
	const MString message;
	const MString place;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////
	
	/**
	 * コンストラクタ。エラーのステータスとメッセージを登録できる。
	 * @param stat エラーのステータス
	 * @param message メッセージ
	 * @param place 発生個所を特定できる文字列
	 */
	MStatusException(const MStatus & stat, const MString & message, const MString & place = "<unlogged>");
	
	/**
	 * デクストラクタ。
	 */
	virtual ~MStatusException();

	/**
	 * 成形されたエラーメッセージを取得する
	 * @return エラーメッセージ
	 */
	MString toString(void) const;

	/**
	 * もしもステータスがkSuccess以外の時に、MStatusExceptionをスローするユーティリティー関数
	 * @param stat エラーのステータス
	 * @param message メッセージ
	 * @param place 発生個所を特定できる文字列
	 * @throws MStatusException ステータスがkSuccess以外だった場合
	 */
	static void throwIfError(const MStatus & stat, const MString & message, const MString & place = "<unlogged>");

protected:

private:
	MStatusException() = delete;
};

};

#endif //end of include guard
