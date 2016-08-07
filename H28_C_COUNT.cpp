﻿
#pragma once

template <class TEMP>
C_COUNT <TEMP> ::
C_COUNT (TEMP _arg_count_max, TEMP _arg_count_min)
{
	_mem_count = _arg_count_min;
	_mem_count_max = _arg_count_max;
	_mem_count_min = _arg_count_min;
	_mem_count_nf_loop = FALSE;
}

template <class TEMP>
C_COUNT <TEMP> ::
C_COUNT (TEMP _arg_count_max, TEMP _arg_count_min, BOOL _arg_count_nf_loop)
{
	_mem_count = _arg_count_min;
	_mem_count_max = _arg_count_max;
	_mem_count_min = _arg_count_min;
	_mem_count_nf_loop = _arg_count_nf_loop;
}

template <class TEMP>
inline TEMP
C_COUNT <TEMP> ::
Ret ()
{
	return _mem_count;
}

template <class TEMP>
inline TEMP
C_COUNT <TEMP> ::
Ret_max ()
{
	return _mem_count_max;
}

template <class TEMP>
inline TEMP
C_COUNT <TEMP> ::
Ret_min ()
{
	return _mem_count_min;
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
Max ()
{
	_mem_count = _mem_count_max;
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
Min ()
{
	_mem_count = _mem_count_min;
}

template <class TEMP>
inline bool
C_COUNT <TEMP> ::
Comp_max ()
{
	if (_mem_count < _mem_count_max)	return true;

	return false;
}

template <class TEMP>
inline bool
C_COUNT <TEMP> ::
Comp_min ()
{
	if (_mem_count > _mem_count_min)	return true;

	return false;
}

template <class TEMP>
inline C_COUNT <TEMP> &
C_COUNT <TEMP> ::
operator = (TEMP _arg_count)
{
	_mem_count = _arg_count;

	return *this;
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
operator ++ (int _arg_count)
{
	_mem_count ++;

	if (_mem_count_max < _mem_count)
	{
		_mem_count = (_mem_count_nf_loop ? _mem_count_min : _mem_count_max);
	}
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
operator -- (int _arg_count)
{
	_mem_count --;

	if (_mem_count_min > _mem_count)
	{
		_mem_count = (_mem_count_nf_loop ? _mem_count_max : _mem_count_min);
	}
}

template <class TEMP>
inline bool
operator == 
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count == _arg_count_comp)	return true;

	return false;
}

template <class TEMP>
inline bool
operator !=
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count != _arg_count_comp)	return true;

	return false;
}

template <class TEMP>
inline bool
operator >=
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count >= _arg_count_comp)	return true;

	return false;
}

template <class TEMP>
inline bool
operator <=
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count <= _arg_count_comp)	return true;

	return false;
}

template <class TEMP>
inline bool
operator >
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count > _arg_count_comp)	return true;

	return false;
}

template <class TEMP>
inline bool
operator <
(
	C_COUNT <TEMP> &_arg_count,
	TEMP _arg_count_comp
)
{
	if (_arg_count._mem_count < _arg_count_comp)	return true;

	return false;
}