/////////////////////////////////////////////////////
//MStatusException.hpp
//
//Copyright (c) 2017 Shotaro Shirao
//
//This software is released under the MIT License.
//http://opensource.org/licenses/mit-license.php
/////////////////////////////////////////////////////

#pragma once
#ifndef CMA_MSTATUSEXCEPTION_HPP_
#define CMA_MSTATUSEXCEPTION_HPP_

#include <maya/MString.h>
#include <maya/MStatus.h>

namespace cma {

/** MStatusException CLASS
 * ����
 */
class MStatusException{
public:
	//////////////////////////////
	// PUBLIC MEMBER CONSTANT
	//////////////////////////////
	const MStatus stat;
	const MString message;
	const MString place;
	
	//////////////////////////////
	// PUBLIC MEMBER FUNCTION
	//////////////////////////////
	
	/**
	 * �R���X�g���N�^�B�G���[�̃X�e�[�^�X�ƃ��b�Z�[�W��o�^�ł���B
	 * @param stat �G���[�̃X�e�[�^�X
	 * @param message ���b�Z�[�W
	 * @param place �����������ł��镶����
	 */
	MStatusException(const MStatus & stat, const MString & message, const MString & place = "<unlogged>");
	
	/**
	 * �f�N�X�g���N�^�B
	 */
	~MStatusException();

	/**
	 * ���`���ꂽ�G���[���b�Z�[�W���擾����
	 * @return �G���[���b�Z�[�W
	 */
	MStatus toString(void) const;

protected:

private:

};

};

#endif //end of include guard
