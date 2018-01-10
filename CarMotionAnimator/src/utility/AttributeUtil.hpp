//TODO:�`��������

#include <MFnAttribute.h>

namespace cma{

/** �A�g���r���[�g�̃t���O�ݒ���ȒP�ɍs�����߂̃��[�e�B���e�B�[�֐�
 * �������A���ꂼ��̊֐��ŋ������قȂ邽�߁A���t�@�����X�͌��d�Ɋm�F���ĉ������B
 * @version 1.0
 * @author S.Shirao
 * @see MFnAttribute
 */

/**
 * �A�g���r���[�g��ݒ肵�܂��B�قڂ��ׂẴp�����[�^��ݒ肵�܂��B
 * �܂��A�����ɗp�ӂ��Ă���p�����[�^�͓���ŁA-1�Ǝw�肵���ꍇ�́u�ύX���Ȃ��v�A1�Ǝw�肵���ꍇ�́utrue�v�A0�Ǝw�肵���ꍇ�́ufalse�v�Ǝw�肳��܂��B
 * �p�����[�^�ɂ��o�O��h�����߁A-1, 0, 1�ȊO���w�肵���ꍇ��MStatusException��InvalidParameter�𓊂��܂��B
 * Maya�̃f�t�H���g�ɗǂ��Ɍv����Ă��炤�ꍇ��-1���w�肵�Ă����ĉ������B
 * �܂��A2018/01���݂�MayaAPI���t�@�����X���f�t�H���g���p���ʂɂĎ����܂��B
 * @see MFnAttribute
 * @param readable �ǂݎ�邱�Ƃ��ł��邩�Btrue�̏ꍇ�A���̃m�[�h�̃f�[�^�\�[�X�Ƃ��Ďg�p���邱�Ƃ��ł��܂��B[true]
 * @param writable �������ނ��Ƃ��ł��邩�Btrue�̏ꍇ�A���̃m�[�h�̏o�͂�ڑ��ł��AsetAttr�R�}���h���������܂��B�܂�keyable�ƂƂ���true�ɂ��邱�ƂŁA�`�����l���{�b�N�X�ɍ��ڂ��\������܂��B[true]
 * @param connectable ���̃m�[�h�Ɛڑ����ł��邩�B[true]
 * @param storable �t�@�C���փf�[�^��ۑ��ł��邩�B[true]
 * @param cached �v�Z���ʂ��������[�փL���b�V���ł��邩�B[true]
 * @param array �f�[�^���z��ł��邩�B���̃m�[�h���畡���̐ڑ����K�v�ȏꍇ��true�ł���K�v������܂��B[false]
 * @param index_matters �f�[�^���z�񂩂ǂݍ��ݕs��(unreadable)�ł���Ƃ��ɁA
 */
extern void setAttrbuteFlags(
    MFnAttribute * attribute,
    const int readable = -1,
    const int writable = -1,
    const int storable = -1,
    const int connectable = -1,
    const int cached = -1,
    const int array = -1,
    const int index_matters = -1,
    const int keyable = -1,
    const int channelbox = -1,
    const int hidden = -1,
    const int used_as_color = -1,
    const int indeterminant = -1,
    const int internal = -1
);

extern void setAttributeFlagsInputPreset(
    MFnAttribute * attribute,
    const bool readable = true,
    const bool array = false,
    const bool keyable = false,
    const bool hidden = false,
    const bool used_as_color = false
);

extern void setAttributeFlagsOutputPreset(
    MFnAttribute * attribute,
    const bool storable = true,
    const bool cached = true, 
    const bool array = false,
    const bool keyable = false,
    const bool channelbox = false,
    const bool hidden = false,
    const bool used_as_color = false,
);

}
