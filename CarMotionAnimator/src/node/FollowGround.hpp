#pragma comment(user, "CarMotionAnimator Plug-in Header")
/////////////////////////////////////////////////////
//FollowGround.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_FOLLOWGROUND_HPP_
#define CMA_FOLLOWGROUND_HPP_

#include <maya/MString.h>
#include <maya/MPxNode.h>
#include <maya/MTypeId.h>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>


namespace cma {

/**
 * これはクラスの説明
 * @version 1.0
 * @author Shirao Shotaro
 * @see MPxNode http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html
 */
class FollowGround : public MPxNode{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	enum { kFollowGroundID = 0x70000 };

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////
	static MObject inMesh;
	static MObject outPoint;
	static MObject rayVector;

	static const MTypeId id;	//ID
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** Constructor
	 */	
	FollowGround();

	/** Destructor
	 */
	virtual ~FollowGround();

	/**
	 * 計算処理部分。距離を測って物体を移動させる
	 * @param plug プラグ
	 * @param data データ
	 */
	virtual MStatus compute(const MPlug & plug, MDataBlock & data) override;

	/**
	 * 新しいインスタンスの生成関数。mayaからコールされる。
	 * @return 新しいインスタンスのnewポインタ
	 */
	static void * creator(void);

	/**
	 * ノード登録時に呼ばれる関数
	 */
	static MStatus initialize(void);

protected:

private:

	/**
	 * inMeshのアトリビュート追加
	 * @throws MStatus ステータスがkSuccess以外の時
	 */
	static void _addAttr_inMesh(void);
	
	/**
	 * inVectorのアトリビュート追加
	 * @throws MStatus ステータスがkSuccess以外の時
	 */
	static void _addAttr_rayVector(void);

	/**
	 * outPointのアトリビュート追加
	 * @throws MStatus ステータスがkSuccess以外の時
	 */
	static void _addAttr_outPoint(void);

};

};

#endif //end of include guard
