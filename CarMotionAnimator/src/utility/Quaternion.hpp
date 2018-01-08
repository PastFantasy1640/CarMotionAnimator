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
 * クオータニオンクラス
 */
class Quaternion{
public:

	//////////////////////////////
	// PUBLIC MEMBER VALIABLES
	//////////////////////////////
	/** パラメータ
	 */
	double w, x, y, z;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////

	/** デフォルトコンストラクタ
	 */	
     Quaternion();

	/** パラメータコンストラクタ
    * @param w wパラメータ
	 * @param x xパラメータ
	 * @param y yパラメータ
	 * @param z zパラメータ
	 */
	Quaternion(const double w, const double x, const double y, const double z);
	
	/** 座標コンストラクタ
	 * @param x xベクトル
     * @param y yベクトル
     * @param z zベクトル
	 */
     Quaternion(const double x, const double y, const double z);

     /** ベクトルからキャスト
      * @param v ベクトル
      */
      template<typename T> Quaternion(const Vector<T> & v);

	/** デストラクタ
	 */
	~Quaternion() {}

	/**
	 * 共役クォータニオンを取得する
	 * @return 共役クォータニオン
	 */
	Quaternion conjugate(void) && const;
	
	/**
	 * ベクトルの乗算処理
	 * @param right 右辺クオータニオン
	 * @return 乗算後のクオータニオン
	 */
	Quaternion operator*(const Quaternion & right) && const;

	/** 表示用文字列に変換
	 * @return 文字列
	 */
	std::string toString(void) const;

protected:

private:

};

};

#endif //end of include guard
