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

/** FollowGround CLASS
 * 説明
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

	/** compute
	 * 計算処理部分。距離を測って物体を移動させる
	 */
	virtual MStatus compute(const MPlug & plug, MDataBlock & data) override;

	/** creator
	 * 新しいインスタンスの生成関数。mayaからコールされる。
	 * @returns 新しいインスタンスのnewポインタ
	 */
	static void * creator(void);

	/** initialize
	 * ノード登録時に呼ばれる関数
	 */
	static MStatus initialize(void);

protected:

private:

};

};

#endif //end of include guard
