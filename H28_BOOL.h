
#pragma once

enum BOOL
{
	TRUE  = 1,
	FALSE = 0,
};

inline BOOL operator & (BOOL _arg_bool_0, BOOL _arg_bool_1);

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
inline BOOL ADD_TF (T _arg_data_0, T _arg_data_1 );
/**
 * \brief _arg_turn_dataのTFを反転させたものをreturnする。
 * 
 * \param _arg_turn_data : 反転させるBOOL
 * 
 * \return BOOL	_arg_turn_dataの反転が返される
 */
template <class T>
inline BOOL TURN_TF (T _arg_turn_data );

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
inline BOOL CHECK_BIT_TF (uint _arg_check_data, T _arg_check_bit );

template <class T>
inline BOOL CHECK_BIT_TF (uint _arg_check_data, T _arg_check_bit_0, T _arg_check_bit_1 );

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
inline BOOL CHECK_TURN_BIT_TF (uint _arg_check_data, T _arg_check_bit );

#include "H28_BOOL.cpp"
