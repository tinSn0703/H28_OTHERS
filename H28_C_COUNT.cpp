
#pragma once

template <class TEMP>
C_COUNT <TEMP> ::
C_COUNT (TEMP _arg_count_max, TEMP _arg_count_min)
{
	_mem_count = _arg_count_min;
	_mem_count_max = _arg_count_max;
	_mem_count_min = _arg_count_min;
	_mem_count_nf_loop = FALSE;
	
	_mem_count_flag = FALSE;
}

template <class TEMP>
C_COUNT <TEMP> ::
C_COUNT (TEMP _arg_count_max, TEMP _arg_count_min, BOOL _arg_count_nf_loop)
{
	_mem_count = _arg_count_min;
	_mem_count_max = _arg_count_max;
	_mem_count_min = _arg_count_min;
	_mem_count_nf_loop = _arg_count_nf_loop;
	
	_mem_count_flag = FALSE;
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
inline BOOL 
C_COUNT <TEMP> :: 
Ret_flag ()
{
	return _mem_count_flag;
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
inline BOOL 
C_COUNT <TEMP> :: 
Comp (TEMP _arg_num_comp)
{
	if (_mem_count == _arg_num_comp)	return TRUE;
	
	return FALSE;
}

template <class TEMP>
inline BOOL
C_COUNT <TEMP> ::
Comp_max ()
{
	if (_mem_count == _mem_count_max)	return TRUE;

	return FALSE;
}

template <class TEMP>
inline BOOL
C_COUNT <TEMP> ::
Comp_min ()
{
	if (_mem_count == _mem_count_min)	return TRUE;

	return FALSE;
}

template <class TEMP>
inline void 
C_COUNT <TEMP> :: 
Flag_up ()
{
	_mem_count_flag = TRUE;
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
Flag_down ()
{
	_mem_count_flag = FALSE;
}

template <class TEMP>
inline void 
C_COUNT <TEMP> :: 
Count_up_flag ()
{
	if (_mem_count_flag)
	{
		_mem_count ++;

		if (_mem_count_max < _mem_count)
		{
			_mem_count = (_mem_count_nf_loop ? _mem_count_min : _mem_count_max);
		}
	}
}

template <class TEMP>
inline void
C_COUNT <TEMP> ::
Count_down_flag ()
{
	if (_mem_count_flag)
	{
		_mem_count --;

		if (_mem_count_min > _mem_count)
		{
			_mem_count = (_mem_count_nf_loop ? _mem_count_max : _mem_count_min);
		}
	}
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
