
#ifndef _I2C_H_
#define _I2C_H_ 1

inline void F_i2c_set();
void F_i2c_out_start(usint );
void F_i2c_in_start(usint );	//�g���
void F_i2c_out(usint );
usint F_i2c_in(char );
void F_i2c_stop();

inline void 
F_i2c_set ()
{
	TWCR = 0x00;
	TWBR = 0x0c;
	TWSR = 0x00;
	TWAR = 0x00;
	TWCR = (1<<TWEN);
}

void 
F_i2c_out_start (usint _arg_set_addr)
{

	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//�J�n����
	while (!(TWCR & (1<<TWINT)));					//�J�n�������M�����ҋ@

	TWDR = _arg_set_addr & 0xfe;		//TWDR�ɃA�h���X���Z�b�g LSB�@0:���M���[�h
	TWCR = ((1<<TWINT) | (1<<TWEN));	//�A�h���X���M�J�n
	while (!(TWCR & (1<<TWINT)));		//���M�����ҋ@
}

void 
F_i2c_in_start (usint _arg_set_addr)
{
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//�J�n����
	while (!(TWCR & (1<<TWINT)));					//�J�n�������M�����ҋ@
	
	TWDR = ((_arg_set_addr & 0xfe) | 1);	//TWDR�ɃA�h���X���Z�b�g LSB�@1:��M���[�h
	TWCR = ((1<<TWINT) | (1<<TWEN));		//�A�h���X���M�J�n
	while (!(TWCR & (1<<TWINT)));			//���M�����ҋ@
}

void 
F_i2c_out (usint _arg_data_out)
{
	TWDR = _arg_data_out;							//�f�[�^�Z�b�g
	TWCR = ((1<<TWINT) | (1<<TWEN));	//TWINT����
	while (!(TWCR & (1<<TWINT)));		//���M�����ҋ@
}

usint 
F_i2c_in (char x)
{
	usint _ret = 0;
	
	if (x == 0)
	{
		TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWEA));	//��M�J�n
	}
	else if (x == 1)
	{
		TWCR = ((1<<TWINT) | (1<<TWEN));
	}

	while (!(TWCR & (1<<TWINT)));	//��M�����ҋ@
	
	_ret = TWDR;

	return _ret;
}

void 
F_i2c_stop ()
{
	TWCR = ((1<<TWINT) | (1<<TWSTO) | (1<<TWEN));		//��~����
	_delay_ms(5);
}

#endif
