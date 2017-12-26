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
 * ����̓N���X�̐���
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
	 * �v�Z���������B�����𑪂��ĕ��̂��ړ�������
	 * @param plug �v���O
	 * @param data �f�[�^
	 */
	virtual MStatus compute(const MPlug & plug, MDataBlock & data) override;

	/**
	 * �V�����C���X�^���X�̐����֐��Bmaya����R�[�������B
	 * @return �V�����C���X�^���X��new�|�C���^
	 */
	static void * creator(void);

	/**
	 * �m�[�h�o�^���ɌĂ΂��֐�
	 */
	static MStatus initialize(void);

protected:

private:

	/**
	 * inMesh�̃A�g���r���[�g�ǉ�
	 * @throws MStatus �X�e�[�^�X��kSuccess�ȊO�̎�
	 */
	static void _addAttr_inMesh(void);
	
	/**
	 * inVector�̃A�g���r���[�g�ǉ�
	 * @throws MStatus �X�e�[�^�X��kSuccess�ȊO�̎�
	 */
	static void _addAttr_rayVector(void);

	/**
	 * outPoint�̃A�g���r���[�g�ǉ�
	 * @throws MStatus �X�e�[�^�X��kSuccess�ȊO�̎�
	 */
	static void _addAttr_outPoint(void);

};

};

#endif //end of include guard
