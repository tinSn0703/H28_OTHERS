
#pragma once

#include <stdlib.h>

template <class TEMP>
class C_STUCK
{
private:

	TEMP *_mem_stuck_data;
	uint _mem_stuck_num_max;
	uint _mem_stuck_num;
	
public:

	C_STUCK <TEMP> ()	{}
	C_STUCK(uint _arg_data_num);
	
	void Push(TEMP );
	TEMP Pop();

	~C_STUCK();
};

#include "H28_C_STUCK.cpp"
