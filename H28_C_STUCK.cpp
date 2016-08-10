
/*
スタック…データが積み重なったような状態にになっていて、一番上
からしかデータを出し入れすることができない。

push データを挿入/積む
pop  データを削除/取り出し
*/

#pragma once

#include "H28_C_STUCK.h"

template <class TEMP>
C_STUCK <TEMP> :: 
C_STUCK (uint _arg_data_num)
{
	_mem_stuck_data = (TEMP *)malloc(_arg_data_num);
	
	if (_mem_stuck_data != NULL)
	{
		_mem_stuck_num_max = _arg_data_num;
		_mem_stuck_num = 0;
	}
}

template <class TEMP>
void 
C_STUCK <TEMP> :: 
Push (TEMP _arg_data_push)
{
	_mem_stuck_data[_mem_stuck_num] = _arg_data_push;

	if(_mem_stuck_num != (_mem_stuck_num_max - 1))	_mem_stuck_num ++;
}

template <class TEMP>
TEMP 
C_STUCK <TEMP> :: 
Pop ()
{
	TEMP _ret_stuck_data_pop = _mem_stuck_data[_mem_stuck_num];
	
	_mem_stuck_data[_mem_stuck_num] = 0;

	if(_mem_stuck_num != 0)	_mem_stuck_num --;

	return _ret_stuck_data_pop;
}

template <class TEMP>
C_STUCK <TEMP> :: 
~C_STUCK()
{
	free(_mem_stuck_data);
}