/////////////////////////////////////////////////////
//[Module name]
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_VECTOR_HPP_
#define CMA_VECTOR_HPP_

#include <cmath>
#include <string>
#include <iostream>
#include <maya/MTypes.h>
#include <maya/MPoint.h>
#include <maya/MVector.h>

namespace cma {

/** Vector CLASS
 * ����
 */
template <typename T> class Vector{
public:

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////
	T x, y, z;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** �f�t�H���g�R���X�g���N�^
	 */	
	Vector()
		: x(static_cast<T>(0.0)), y(static_cast<T>(0.0)), z(static_cast<T>(0.0)) {}

	/** �p�����[�^�R���X�g���N�^
	 */
	Vector(const T x, const T y, const T z)
		: x(x), y(y), z(z) {}
	
	/** �L���X�g�I�R���X�g���N�^
	 */
	template <typename N> Vector(const N & cast);

	/** Vector�L���X�g�R���X�g���N�^
	 */
	template <typename N> Vector(const Vector<N> & cast);
	
	/** MPoint����̃R���X�g���N�^
	 */
	Vector(MPoint m_point);

	/** MVector����̃R���X�g���N�^
	 */
	Vector(MVector m_vector);

	/** �f�X�g���N�^
	 */
	~Vector() {}

	/**
	 * �x�N�g���̒������v�Z����
	 * @return �x�N�g���̒���
	 */
	template <typename N> N length(void) const;

	/**
	 * �t�����̃x�N�g�����擾����
	 * @return �t�����x�N�g��
	 */
	Vector<T> inv(void) const;
	
	/**
	 * �x�N�g�����m�̉��Z����
	 * @param v ���Z����x�N�g��
	 * @return ���Z��̃x�N�g��
	 */
	Vector<T> operator+(const Vector<T> & v) const;

	/**
	 * �x�N�g�����m�̌��Z����
	 * @param v ���Z����x�N�g��
	 * @return ���Z��̃x�N�g��
	 */
	Vector<T> operator-(const Vector<T> & v) const;

	/** �\���p������ɕϊ�
	 * @return ������
	 */
	std::string toString(void) const;

	/**
	 * �O�ς����߂�
	 * @param v1 �x�N�g��1
	 * @param v2 �x�N�g��2
	 * @param v3 �x�N�g��3
	 * @return �O��
	 */
	static T det(const Vector<T> & v1, const Vector<T> & v2, const Vector<T> & v3);

protected:

private:

};

template class Vector<int>;
template class Vector<double>;
template class Vector<float>;

template<> template<>
inline cma::Vector<double>::Vector(const double3 & cast) {
	this->x = cast[0]; this->y = cast[1]; this->z = cast[2];
}

template<> template<>
inline cma::Vector<float>::Vector(const float3 & cast) {
	this->x = cast[0]; this->y = cast[1]; this->z = cast[2];
}

template<> template<>
inline cma::Vector<int>::Vector(const int3 & cast) {
	this->x = cast[0]; this->y = cast[1]; this->z = cast[2];
}

template<typename T>
template<typename N>
inline cma::Vector<T>::Vector(const Vector<N> & cast) {
	this->x = static_cast<T>(cast.x);
	this->y = static_cast<T>(cast.y);
	this->z = static_cast<T>(cast.z);
}

template<typename T>
template<typename N>
inline N Vector<T>::length(void) const {
	return static_cast<N>(
		std::sqrt(
			static_cast<double>(this->x) * this->x + 
			static_cast<double>(this->y) * this->y +
			static_cast<double>(this->z) * this->z
		)
	);
}

typedef Vector<double> VectorD;
typedef Vector<float> VectorF;
typedef Vector<int> VectorI;

template<typename T>
inline Vector<T>::Vector(MPoint m_point) {
	m_point.cartesianize();
	this->x = static_cast<T>(m_point.x);
	this->y = static_cast<T>(m_point.y);
	this->z = static_cast<T>(m_point.z);
}

template<typename T>
inline Vector<T>::Vector(MVector m_vector) {
	this->x = static_cast<T>(m_vector.x);
	this->y = static_cast<T>(m_vector.y);
	this->z = static_cast<T>(m_vector.z);
}

template<typename T>
inline Vector<T> Vector<T>::inv(void) const {
	return Vector<T>(-this->x, -this->y, -this->z);
}

template<typename T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& v) const {
	return Vector<T>(this->x + v.x, this->y + v.y, this->z + v.z);
}

template<typename T>
inline Vector<T> Vector<T>::operator-(const Vector<T>& v) const {
	return Vector<T>(this->x - v.x, this->y - v.y, this->z - v.z);
}

template<typename T>
inline std::string Vector<T>::toString(void) const {
	return std::string("(x, y, z) = (" + 
		std::to_string(this->x) + ", " +
		std::to_string(this->y) + ", " +
		std::to_string(this->z) + ")");
}

template<typename T>
inline T Vector<T>::det(const Vector<T>& v1, const Vector<T>& v2, const Vector<T>& v3) {
	return ((v1.x * v2.y * v3.z)
          + (v1.y * v2.z * v3.x)
          + (v1.z * v2.x * v3.y)
          - (v1.x * v2.z * v3.y)
          - (v1.y * v2.x * v3.z)
          - (v1.z * v2.y * v3.x));
}

};

#endif //end of include guard
