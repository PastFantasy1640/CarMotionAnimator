/////////////////////////////////////////////////////
//KeepDistanceNode.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_KEEPDISTANCENODE_HPP_
#define CMA_KEEPDISTANCENODE_HPP_

#include <maya/MString.h>
#include <maya/MPxNode.h>
#include <maya/MTypeId.h>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>


namespace cma {

/** KeepDistanceNode CLASS
 * ����
 */
class KeepDistanceNode : public MPxNode{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	enum { kKeepDistanceNodeID = 0x70000 };

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
	KeepDistanceNode();

	/** Destructor
	 */
	virtual ~KeepDistanceNode();

	/** compute
	 * �v�Z���������B�����𑪂��ĕ��̂��ړ�������
	 */
	virtual MStatus compute(const MPlug & plug, MDataBlock & data) override;

	/** creator
	 * �V�����C���X�^���X�̐����֐��Bmaya����R�[�������B
	 * @returns �V�����C���X�^���X��new�|�C���^
	 */
	static void * creator(void);

	/** initialize
	 * �m�[�h�o�^���ɌĂ΂��֐�
	 */
	static MStatus initialize(void);

protected:

private:

};

};

#endif //end of include guard
