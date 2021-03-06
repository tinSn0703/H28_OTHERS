﻿
#pragma once

inline BOOL
operator ~ (BOOL _arg_bool)
{
	return (BOOL)((~(int)_arg_bool) & 1);
}

inline BOOL
operator &
(
	BOOL _arg_bool_0,
	BOOL _arg_bool_1
)
{
	return (BOOL)(((int)_arg_bool_0 & (int)_arg_bool_1) & 1);
}

inline BOOL
operator |
(
	BOOL _arg_bool_0,
	BOOL _arg_bool_1
)
{
	return (BOOL)(((int)_arg_bool_0 | (int)_arg_bool_1) & 1);
}

template <class T>
inline BOOL
F_Func_and_bool
(
	T _arg_data_0,
	T _arg_data_1
)
{
	return (BOOL)((_arg_data_0 & _arg_data_1) & 1);
}

template <class T>
inline BOOL
F_Turn_bool (T _arg_turn_data )
{
	return (BOOL)((~(int)_arg_turn_data) & 1);
}

template <class T>
inline BOOL
F_Check_bit_bool
(
	int _arg_check_data,
	T _arg_check_bit
)
{
	return (BOOL)((_arg_check_data >> _arg_check_bit) & 1);
}

template <class T>
inline BOOL
F_Check_bit_bool
(
	int _arg_check_data,
	T _arg_check_bit_0,
	T _arg_check_bit_1
)
{
	return (BOOL)((_arg_check_data >> _arg_check_bit_0) & (_arg_check_data >> _arg_check_bit_1) & 1);
}

template <class T>
inline BOOL
F_Check_turn_bit_bool
(
	int _arg_check_data,
	T _arg_check_bit
)
{
	return F_Turn_bool(_arg_check_data >> _arg_check_bit);
}
