
#ifndef _I2C_H_
#define _I2C_H_ 1

inline void F_I2c_set();
void F_I2c_out_start(usint );
void F_I2c_in_start(usint );	//�g���
void F_I2c_out(usint );
usint F_I2c_in(BOOL );
void F_I2c_stop();

inline void 
F_I2c_set ()
{
	TWCR = 0x00;
	TWBR = 0x0c;
	TWSR = 0x00;
	TWAR = 0x00;
	TWCR = (1<<TWEN);
}

void 
F_I2c_out_start (usint _arg_set_addr)
{

	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//�J�n����
	while (!(TWCR & (1<<TWINT)));					//�J�n�������M�����ҋ@

	TWDR = _arg_set_addr & 0xfe;		//TWDR�ɃA�h���X���Z�b�g LSB�@0:���M���[�h
	TWCR = ((1<<TWINT) | (1<<TWEN));	//�A�h���X���M�J�n
	while (!(TWCR & (1<<TWINT)));		//���M�����ҋ@
}

void 
F_I2c_in_start (usint _arg_set_addr)
{
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//�J�n����
	while (!(TWCR & (1<<TWINT)));					//�J�n�������M�����ҋ@
	
	TWDR = ((_arg_set_addr & 0xfe) | 1);	//TWDR�ɃA�h���X���Z�b�g LSB�@1:��M���[�h
	TWCR = ((1<<TWINT) | (1<<TWEN));		//�A�h���X���M�J�n
	while (!(TWCR & (1<<TWINT)));			//���M�����ҋ@
}

void 
F_I2c_out (usint _arg_data_out)
{
	TWDR = _arg_data_out;							//�f�[�^�Z�b�g
	TWCR = ((1<<TWINT) | (1<<TWEN));	//TWINT����
	while (!(TWCR & (1<<TWINT)));		//���M�����ҋ@
}

usint 
F_I2c_in (BOOL _arg_nf_ack)
{
	usint _ret = 0;
	
	if (_arg_nf_ack)
	{
		TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWEA));	//��M�J�n
	}
	else
	{
		TWCR = ((1<<TWINT) | (1<<TWEN));
	}

	while (!(TWCR & (1<<TWINT)));	//��M�����ҋ@
	
	_ret = TWDR;

	return _ret;
}

void 
F_I2c_stop ()
{
	TWCR = ((1<<TWINT) | (1<<TWSTO) | (1<<TWEN));		//��~����
	_delay_ms(5);
}

#endif

