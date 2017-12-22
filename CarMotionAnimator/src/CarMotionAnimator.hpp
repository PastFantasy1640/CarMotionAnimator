/////////////////////////////////////////////////////
//CarMotionAnimator.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

//���\�z���ɎQ�l�ɂ���URL
//�yMaya C++�zMaya C++�̎n�ߕ�(maya2017 update4)
//https://unpyside.wixsite.com/unpyside/single-post/2017/07/03/%E3%80%90Maya-C%E3%80%91Maya-C%E3%81%AE%E5%A7%8B%E3%82%81%E6%96%B9maya2017-update4


#pragma once
#ifndef CMA_CARMOTIONANIMATOR_HPP_
#define CMA_CARMOTIONANIMATOR_HPP_

#include <maya/MFnPlugin.h>
#include <maya/MObject.h>

namespace cma {

/** initializePlugin
 * �v���O�C���̏������������s���Bmaya������R�[�������֐��B
 */
extern MStatus initializePlugin(MObject _obj);

/** uninitializePlugin
 * �v���O�C���̃A�����[�h�������s���Bmaya������R�[�������֐��B
 */
extern MStatus uninitializePlugin(MObject _obj);

};

#endif //end of include guard
