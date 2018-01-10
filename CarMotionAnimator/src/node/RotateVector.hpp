#pragma comment(user, "CarMotionAnimator Plug-in Header")
/////////////////////////////////////////////////////
//RotateVector.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_QUATERNION_HPP_
#define CMA_QUATERNION_HPP_

#include <maya/MString.h>
#include <maya/MPxNode.h>
#include <maya/MTypeId.h>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MPointArray.h>
#include "utility/Quaternion.hpp"

namespace cma {

/**
 * ベクトルを回転させるユーティリティーノード
 * @version 1.0
 * @see MPxNode http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html
 */
class RotateVector : public MPxNode{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////


	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////

	/** 入力ベクトル
	 */
	static MObject inVector;

	/** 入力回転
	 */
	static MObject rotate_quaternion;

	/** 出力ベクトル
	 */
	static MObject outVector;
	
	/** ベクトルサイズ
	 */
	static MObject length;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** コンストラクタ
	 */	
	RotateVector();

	/** デストラクタ
	 */
	virtual ~RotateVector();

	/**
	 * ベクトルを回転させる
	 * @param plug 計算中のプラグ
	 * @param data 編集可能な内部データ
	 * @return 計算に成功した場合kSuccessを返す
	 * @see MPxNode::compute http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html#3dd5454e3fa92598836018ae9ab220c3
	 */
	virtual MStatus compute(const MPlug & plug,	MDataBlock & data) override;

	/**
	 * 新しいインスタンスの生成関数
	 * @return 新しいインスタンスのnewポインタ
	 */
	static void * creator(void);

	/**
	 * ノード登録時に呼ばれる関数
	 * @return 初期化に成功した場合kSuccessを返す
	 */
	static MStatus initialize(void);

protected:

private:
	
};

};

#endif //end of include guard
