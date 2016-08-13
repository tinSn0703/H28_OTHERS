
#pragma once

template <class TEMP>
class C_COUNT;

template <class TEMP>
bool operator == (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
bool operator != (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
bool operator >= (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
bool operator <= (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
bool operator > (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
bool operator < (C_COUNT <TEMP> &,TEMP );

template <class TEMP>
class C_COUNT
{
private:

	TEMP _mem_count;
	TEMP _mem_count_max;
	TEMP _mem_count_min;
	
	BOOL _mem_count_nf_loop :1;
	
	BOOL _mem_count_flag :1;
	
public:

	C_COUNT <TEMP> () {}
	C_COUNT (TEMP ,TEMP);
	C_COUNT (TEMP ,TEMP ,BOOL );
	
	TEMP Ret();
	TEMP Ret_max();
	TEMP Ret_min();
	
	BOOL Ret_flag();
	
	void Max();
	void Min();
	
	bool Comp_max();
	bool Comp_min();
	
	void Flag_up();
	void Flag_down();
	
	C_COUNT <TEMP> & operator = (TEMP );

	void operator ++ (int );
	void operator -- (int );

	friend bool operator == <TEMP> (C_COUNT <TEMP> &,TEMP );
	friend bool operator != <TEMP> (C_COUNT <TEMP> &,TEMP );
	
	friend bool operator >= <TEMP> (C_COUNT <TEMP> &,TEMP );
	friend bool operator <= <TEMP> (C_COUNT <TEMP> &,TEMP );

	friend bool operator > <TEMP> (C_COUNT <TEMP> &,TEMP );
	friend bool operator < <TEMP> (C_COUNT <TEMP> &,TEMP );
};

#include "H28_C_COUNT.cpp"

typedef C_COUNT <char>	C_COUNT_1;
typedef C_COUNT <uchar>	C_COUNT_u1;
typedef C_COUNT <sint>	C_COUNT_2;
typedef C_COUNT <usint>	C_COUNT_u2;
typedef C_COUNT <int>	C_COUNT_4;
typedef C_COUNT <uint>	C_COUNT_u4;
