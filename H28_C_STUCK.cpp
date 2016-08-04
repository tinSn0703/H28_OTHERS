
/*
�X�^�b�N�c�f�[�^���ςݏd�Ȃ����悤�ȏ�ԂɂɂȂ��Ă��āA��ԏ�
���炵���f�[�^���o�����ꂷ�邱�Ƃ��ł��Ȃ��B

push �f�[�^��}��/�ς�
pop  �f�[�^���폜/���o��
*/

#include <stdlib.h>

template <class TEMP>
class C_STUCK
{
	private:
	TEMP *_mem_stuck_data;
	unsigned int _mem_stuck_num_max;
	unsigned int _mem_stuck_num;
	
	public:
	C_STUCK()	{}
	C_STUCK(unsigned int );
	
	void Push(TEMP );
	TEMP Pop();

	~C_STUCK();
};

template <class TEMP>
C_STUCK <TEMP> :: C_STUCK(unsigned int _arg_stuck_data_num)
{
	_mem_stuck_data = (TEMP *)malloc(_arg_stuck_data_num);
	_mem_stuck_num_max = _arg_stuck_data_num;
	_mem_stuck_num = 0;
}

template <class TEMP>
void C_STUCK <TEMP> :: Push(TEMP _arg_stuck_data_push)
{
	_mem_stuck_data[_mem_stuck_num] = _arg_stuck_data_push;

	if(_mem_stuck_num != (_mem_stuck_num_max - 1))	_mem_stuck_num += 1;
}

template <class TEMP>
TEMP C_STUCK <TEMP> :: Pop()
{
	TEMP _ret_stuck_data_pop = _mem_stuck_data[_mem_stuck_num];
	
	_mem_stuck_data[_mem_stuck_num] = NULL;

	if(_mem_stuck_num != 0)	_mem_stuck_num -= 1;

	return _ret_stuck_data_pop;
}

template <class TEMP>
C_STUCK <TEMP> :: ~C_STUCK()
{
	delete[] _mem_stuck_data;
}