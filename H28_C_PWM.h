
#pragma once

#include "H28_C_COUNT.h"

class C_PWM
{
private:
	
	C_TIMER		_mem_pwm_timer;
	C_COUNT_UL	_mem_pwm_count;
	C_IO_OUT	_mem_pwm_io_out;
	T_PORT		_mem_pwm_io_set :8;
	ulint		_mem_pwm_limit[8];
	
public:
	
	C_PWM()	{}
		
#if defined(_AVR_IOM640_H_)
	C_PWM(E_TIMER_ADDR ,E_IO_PORT_ADDR ,ulint );
#elif defined(_AVR_IOM164_H_)
	C_PWM(E_IO_PORT_ADDR ,ulint);
#endif
	
	void Set(E_IO_NUM ,ulint );
	void Start();
};

#include "H28_C_PWM.cpp"
