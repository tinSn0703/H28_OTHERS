
#include "H28_C_PWM.h"

#if defined(_AVR_IOM640_H_)
C_PWM ::
C_PWM
(
	E_TIMER_ADDR   _arg_pwm_timer,
	E_IO_PORT_ADDR _arg_pwm_io_out,
	ulint _arg_pwm_count_max
)
: _mem_pwm_timer (_arg_pwm_timer,ET_OVERFLOW,EC_8,65421) //正確には0.092だけど実際の実行時間はだいたい0.1ms
, _mem_pwm_count (_arg_pwm_count_max, 0)
, _mem_pwm_io_out(_arg_pwm_io_out,0xff)
{
	for (usint i = 0; i < 8; i++)
	{
		_mem_pwm_limit[i] = _arg_pwm_count_max;
	}
	
	_mem_pwm_io_set = 0;
}
#elif defined(_AVR_IOM164_H_)
C_PWM ::
C_PWM
(
	E_IO_PORT_ADDR _arg_pwm_io_out,
	ulint _arg_pwm_count_max
)
: _mem_pwm_timer (ET_OVERFLOW,EC_8,65421) //正確には0.092だけど実際の実行時間はだいたい0.1ms
, _mem_pwm_count (_arg_pwm_count_max, 0)
, _mem_pwm_io_out(_arg_pwm_io_out,0xff)
{
	for (usint i = 0; i < 8; i++)
	{
		_mem_pwm_limit[i] = _arg_pwm_count_max;
	}
	
	_mem_pwm_io_set = 0;
}
#endif

void
C_PWM ::
Set
(
	E_IO_NUM _arg_pwm_set_num,
	ulint _arg_pwm_count_limit
)
{
	if (_mem_pwm_count.Ret_max() > _arg_pwm_count_limit)
	{
		_mem_pwm_limit[_arg_pwm_set_num] = _arg_pwm_count_limit - 1;
	}
	else
	{
		_mem_pwm_limit[_arg_pwm_set_num] = _mem_pwm_count.Ret_max();
	}
	
	_mem_pwm_io_set |= (1 << _arg_pwm_set_num);
}

void
C_PWM ::
Start ()
{
	_mem_pwm_count.Min();
	
	_mem_pwm_io_out.Out(_mem_pwm_io_set);
	
	_mem_pwm_timer.Start();
	
	while (_mem_pwm_count.Comp_max())
	{
		for (usint i = 0; i < 8; i++)
		{
			if (_mem_pwm_count == _mem_pwm_limit[i])
			{
				_mem_pwm_io_out.Out_num_off(i);
			}
		}
		
		while (_mem_pwm_timer.Flag_timer_overflow() == FALSE);
		
		_mem_pwm_count ++;
	}
}