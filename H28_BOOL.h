
#pragma once

#include "H28_typedef.h"

enum BOOL
{
	TRUE  = 1,
	FALSE = 0,
};

/**
 * \brief 
 *	_arg_bool��TRUE,FALSE�𔽓]���������̂�return����BTRUN_TF()�̉��Z�qver  
 *
 * \param _arg_bool : ��
 * 
 * \return BOOL : ���]��̂���
 */
inline BOOL operator ~ (BOOL _arg_bool);

/**
 * \brief 
 *	BOOL�p�̘_����
 *	
 *	 0�_1 | TRUE  | FALSE
 *		  |		  |
 *	TRUE  |	TRUE  |	FALSE
 *		  |		  |
 *	FALSE |	FALSE |	FALSE
 *
 * \param _arg_bool_0 : ����
 * \param _arg_bool_1 : �E��
 * 
 * \return BOOL : ����
 */
inline BOOL operator & (BOOL _arg_bool_0, BOOL _arg_bool_1);

/**
 * \brief 
 *	BOOL�p�̘_���a
 *	
 *	 0�_1 | TRUE  | FALSE
 *		  |		  |
 *	TRUE  |	TRUE  |	TRUE
 *		  |		  |
 *	FALSE |	TRUE  |	FALSE
 *
 * \param _arg_bool_0 : ����
 * \param _arg_bool_1 : �E��
 * 
 * \return BOOL : ����
 */
inline BOOL operator | (BOOL _arg_bool_0, BOOL _arg_bool_1);

/**
 * \brief _arg_data_0��_arg_data_1��0bit��BOOL�ɍ�������
 * 
 * \param _arg_data_0 : �����ޗ�0
 * \param _arg_data_1 : �����ޗ�1
 * 
 * \return BOOL
 *	  1   |   0   | ����
 *	TRUE  | TRUE  | TRUE
 *	FALSE | TRUE  | FALSE
 *	TRUE  | FALSE | FALSE
 *	FALSE | FALSE | FALSE
 */
template <class T>
inline BOOL F_Func_and_bool (T _arg_data_0, T _arg_data_1 );

/**
 * \brief _arg_turn_data��TF�𔽓]���������̂�return����B
 * 
 * \param _arg_turn_data : ���]������BOOL
 * 
 * \return BOOL	_arg_turn_data�̔��]���Ԃ����
 */
template <class T>
inline BOOL F_Turn_bool (T _arg_turn_data );

/**
 * \brief _arg_check_data��_arg_check_bit��TF�ɕϊ��������̂�return����B
 * 
 * \param _arg_check_data : �T�����f�[�^
 * \param _arg_check_bit  : �m�F����bit
 * 
 * \return BOOL
 *	0 -> FALSE
 *	1 -> TRUE
 */
template <class T>
inline BOOL F_Check_bit_bool (int _arg_check_data, T _arg_check_bit );

template <class T>
inline BOOL F_Check_bit_bool (int _arg_check_data, T _arg_check_bit_0, T _arg_check_bit_1 );

/**
 * \brief CHECK_BIT_TF�̔��]ver
 * 
 * \param _arg_check_data : �T�����f�[�^
 * \param _arg_check_bit  : �m�F����bit
 *
 * \return BOOL
 *	0 -> FALSE
 *	1 -> TRUE
 */
template <class T>
inline BOOL F_Check_turn_bit_bool (int _arg_check_data, T _arg_check_bit );

#include "H28_BOOL.cpp"
