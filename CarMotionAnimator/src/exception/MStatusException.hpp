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
	virtual ~MStatusException();

	/**
	 * ���`���ꂽ�G���[���b�Z�[�W���擾����
	 * @return �G���[���b�Z�[�W
	 */
	MString toString(void) const;

	/**
	 * �������X�e�[�^�X��kSuccess�ȊO�̎��ɁAMStatusException���X���[���郆�[�e�B���e�B�[�֐�
	 * @param stat �G���[�̃X�e�[�^�X
	 * @param message ���b�Z�[�W
	 * @param place �����������ł��镶����
	 * @throws MStatusException �X�e�[�^�X��kSuccess�ȊO�������ꍇ
	 */
	static void throwIfError(const MStatus & stat, const MString & message, const MString & place = "<unlogged>");

protected:

private:
	MStatusException() = delete;
};

};

#endif //end of include guard
