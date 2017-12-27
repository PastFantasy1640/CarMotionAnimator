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
#include <maya/MTypes.h>

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
	Vector() : x(static_cast<T>(0.0)), y(static_cast<T>(0.0)), z(static_cast<T>(0.0)) {}

	/** �p�����[�^�R���X�g���N�^
	 */
	Vector(const T x, const T y, const T z) : x(x), y(y), z(z) {}

	/** �L���X�g�I�R���X�g���N�^
	 */
	template <typename N> Vector(const N & cast);

	/** �f�X�g���N�^
	 */
	~Vector() {}

	/**
	 * �x�N�g���̒������v�Z����
	 * @return �x�N�g���̒���
	 */
	template <typename N> N length(void) const;

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

};

#endif //end of include guard
