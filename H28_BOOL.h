
#pragma once

#include "H28_typedef.h"

enum BOOL
{
	TRUE  = 1,
	FALSE = 0,
};

/**
 * \brief 
 *	_arg_boolのTRUE,FALSEを反転させたものをreturnする。TRUN_TF()の演算子ver  
 *
 * \param _arg_bool : 元
 * 
 * \return BOOL : 反転後のもの
 */
inline BOOL operator ~ (BOOL _arg_bool);

/**
 * \brief 
 *	BOOL用の論理積
 *	
 *	 0＼1 | TRUE  | FALSE
 *		  |		  |
 *	TRUE  |	TRUE  |	FALSE
 *		  |		  |
 *	FALSE |	FALSE |	FALSE
 *
 * \param _arg_bool_0 : 左辺
 * \param _arg_bool_1 : 右辺
 * 
 * \return BOOL : 結果
 */
inline BOOL operator & (BOOL _arg_bool_0, BOOL _arg_bool_1);

/**
 * \brief 
 *	BOOL用の論理和
 *	
 *	 0＼1 | TRUE  | FALSE
 *		  |		  |
 *	TRUE  |	TRUE  |	TRUE
 *		  |		  |
 *	FALSE |	TRUE  |	FALSE
 *
 * \param _arg_bool_0 : 左辺
 * \param _arg_bool_1 : 右辺
 * 
 * \return BOOL : 結果
 */
inline BOOL operator | (BOOL _arg_bool_0, BOOL _arg_bool_1);

/**
 * \brief _arg_data_0と_arg_data_1の0bitをBOOLに合成する
 * 
 * \param _arg_data_0 : 合成材料0
 * \param _arg_data_1 : 合成材料1
 * 
 * \return BOOL
 *	  1   |   0   | 結果
 *	TRUE  | TRUE  | TRUE
 *	FALSE | TRUE  | FALSE
 *	TRUE  | FALSE | FALSE
 *	FALSE | FALSE | FALSE
 */
template <class T>
inline BOOL F_Func_and_bool (T _arg_data_0, T _arg_data_1 );

/**
 * \brief _arg_turn_dataのTFを反転させたものをreturnする。
 * 
 * \param _arg_turn_data : 反転させるBOOL
 * 
 * \return BOOL	_arg_turn_dataの反転が返される
 */
template <class T>
inline BOOL F_Turn_bool (T _arg_turn_data );

/**
 * \brief _arg_check_dataの_arg_check_bitをTFに変換したものをreturnする。
 * 
 * \param _arg_check_data : 探されるデータ
 * \param _arg_check_bit  : 確認するbit
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
 * \brief CHECK_BIT_TFの反転ver
 * 
 * \param _arg_check_data : 探されるデータ
 * \param _arg_check_bit  : 確認するbit
 *
 * \return BOOL
 *	0 -> FALSE
 *	1 -> TRUE
 */
template <class T>
inline BOOL F_Check_turn_bit_bool (int _arg_check_data, T _arg_check_bit );

#include "H28_BOOL.cpp"
