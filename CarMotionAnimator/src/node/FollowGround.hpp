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
 * FollowGround�m�[�h�N���X
 * �n�_����̃x�N�g�����C�ƁA�n�ʂƂ̌�_���W���Z�o����m�[�h
 * @version 1.0
 * @see MPxNode http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html
 */
class FollowGround : public MPxNode{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	/**
	 * �m�[�hID�萔
	 */
	enum { kFollowGroundID = 0x70000 };

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////

	/** ���̓��b�V��
	 * �n�ʂƂ��Ďg�p�����B
	 */
	static MObject inMesh;

	/** �o�̓|�C���g
	 * �n�ʂɐڂ���_�̍��W
	 */
	static MObject outPoint;

	/** ���̓x�N�g��
	 * �n�_����̃x�N�g�����C
	 */
	static MObject rayVector;

	/** ���C�n�_
	 */
	static MObject rayPoint;

	/** �m�[�hID
	 */
	static const MTypeId id;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** �R���X�g���N�^
	 */	
	FollowGround();

	/** �f�X�g���N�^
	 */
	virtual ~FollowGround();

	/**
	 * �m�[�h�̌v�Z��������
	 * �����𑪂��ĕ��̂��ړ�������
	 * @param plug �v�Z���̃v���O
	 * @param data �ҏW�\�ȓ����f�[�^
	 * @return �v�Z�ɐ��������ꍇkSuccess��Ԃ�
	 * @see MPxNode::compute http://download.autodesk.com/us/maya/2011help/api/class_m_px_node.html#3dd5454e3fa92598836018ae9ab220c3
	 */
	virtual MStatus compute(const MPlug & plug,	MDataBlock & data) override;

	/**
	 * �V�����C���X�^���X�̐����֐�
	 * @return �V�����C���X�^���X��new�|�C���^
	 */
	static void * creator(void);

	/**
	 * �m�[�h�o�^���ɌĂ΂��֐�
	 * @return �������ɐ��������ꍇkSuccess��Ԃ�
	 */
	static MStatus initialize(void);

protected:

private:

	/**
	 * inMesh�̃A�g���r���[�g�ǉ�
	 * @throws MStatusException �X�e�[�^�X��kSuccess�ȊO�̎��ɁA�ڍׂ��܂߂ė�O�𓊂���
	 * @see cma::MStatusException
	 */
	static void _addAttr_inMesh(void);
	
	/**
	 * inVector�̃A�g���r���[�g�ǉ�
	 * @throws MStatusException �X�e�[�^�X��kSuccess�ȊO�̎��ɁA�ڍׂ��܂߂ė�O�𓊂���
	 * @see cma::MStatusException
	 */
	static void _addAttr_rayVector(void);
	
	/**
	 * outPoint�̃A�g���r���[�g�ǉ�
	 * @throws MStatusException �X�e�[�^�X��kSuccess�ȊO�̎��ɁA�ڍׂ��܂߂ė�O�𓊂���
	 * @see cma::MStatusException
	 */
	static void _addAttr_outPoint(void);

	/**
	 * rayPoint�̃A�g���r���[�g�ǉ�
	 * @throws MStatusException �X�e�[�^�X��kSuccess�ȊO�̎��ɁA�ڍׂ��܂߂ė�O�𓊂���
	 * @see cma::MStatusException
	 */
	static void _addAttr_rayPoint(void);

	/**
	 * �Čv�Z(compute)���Ɏg�p����A�g���r���[�g�l�̎擾
	 * @param data compute�֐��̈����ł���data�̎Q��
	 * @param ground �O���E���h
	 * @param ray_from ���C�n�_
	 * @param ray_vector ���C�x�N�g��
	 * @throws MStatusException ���ꂼ��̎擾���ʂ�kSuccess�ȊO�������ꍇ
	 * @see cma::MStatusException
	 */
	static void _getInputValue(MDataBlock & data, MDataHandle * ground, MDataHandle * ray_from, MDataHandle * ray_vector);

	/**
	 * �Čv�Z���ꂽ�l���A�g���r���[�g�֔��f������
	 * @param data compute�֐��̈����ł���data�̎Q��
	 * @param result �i�[���錋�ʂ̒l
	 * @throws MStatusException �i�[���̌��ʂ�kSuccess�ȊO�������ꍇ
	 * @see cma::MStatusException
	 */
	static void _setOutputValue(MDataBlock & data, const float x, const float y, const float z);

};

};

#endif //end of include guard
