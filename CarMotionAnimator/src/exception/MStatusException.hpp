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
	~MStatusException();

	/**
	 * 成形されたエラーメッセージを取得する
	 * @return エラーメッセージ
	 */
	MStatus toString(void) const;

protected:

private:

};

};

#endif //end of include guard
