#pragma comment(user, "CarMotionAnimator Plug-in Header")
/////////////////////////////////////////////////////
//Quaternion.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_QUATERNION_HPP_
#define CMA_QUATERNION_HPP_

#include <cmath>
#include <string>
#include <iostream>
#include <maya/MTypes.h>
#include <maya/MPoint.h>
#include <maya/MVector.h>

namespace cma {

/** 
 * �N�I�[�^�j�I���N���X
 */
class Quaternion{
public:

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////
	/** �p�����[�^
	 */
	double w, x, y, z;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** �f�t�H���g�R���X�g���N�^
	 */	
     Quaternion();

	/** �p�����[�^�R���X�g���N�^
    * @param w w�p�����[�^
	 * @param x x�p�����[�^
	 * @param y y�p�����[�^
	 * @param z z�p�����[�^
	 */
	Quaternion(const double w, const double x, const double y, const double z);
	
	/** ���W�R���X�g���N�^
	 * @param x x�x�N�g��
     * @param y y�x�N�g��
     * @param z z�x�N�g��
	 */
     Quaternion(const double x, const double y, const double z);

     /** �x�N�g������L���X�g
      * @param v �x�N�g��
      */
      template<typename T> Quaternion(const Vector<T> & v);

	/** �f�X�g���N�^
	 */
	~Quaternion() {}

	/**
	 * �����N�H�[�^�j�I�����擾����
	 * @return �����N�H�[�^�j�I��
	 */
	Quaternion conjugate(void) && const;
	
	/**
	 * �x�N�g���̏�Z����
	 * @param right �E�ӃN�I�[�^�j�I��
	 * @return ��Z��̃N�I�[�^�j�I��
	 */
	Quaternion operator*(const Quaternion & right) && const;

	/** �\���p������ɕϊ�
	 * @return ������
	 */
	std::string toString(void) const;

protected:

private:

};

};

#endif //end of include guard
