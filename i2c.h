
#ifndef _I2C_H_
#define _I2C_H_ 1

inline void F_I2c_set();
void F_I2c_out_start(usint );
void F_I2c_in_start(usint );	//使わん
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

	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//開始条件
	while (!(TWCR & (1<<TWINT)));					//開始条件送信完了待機

	TWDR = _arg_set_addr & 0xfe;		//TWDRにアドレスをセット LSB　0:送信モード
	TWCR = ((1<<TWINT) | (1<<TWEN));	//アドレス送信開始
	while (!(TWCR & (1<<TWINT)));		//送信完了待機
}

void 
F_I2c_in_start (usint _arg_set_addr)
{
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));	//開始条件
	while (!(TWCR & (1<<TWINT)));					//開始条件送信完了待機
	
	TWDR = ((_arg_set_addr & 0xfe) | 1);	//TWDRにアドレスをセット LSB　1:受信モード
	TWCR = ((1<<TWINT) | (1<<TWEN));		//アドレス送信開始
	while (!(TWCR & (1<<TWINT)));			//送信完了待機
}

void 
F_I2c_out (usint _arg_data_out)
{
	TWDR = _arg_data_out;							//データセット
	TWCR = ((1<<TWINT) | (1<<TWEN));	//TWINT解除
	while (!(TWCR & (1<<TWINT)));		//送信完了待機
}

usint 
F_I2c_in (BOOL _arg_nf_ack)
{
	usint _ret = 0;
	
	if (_arg_nf_ack)
	{
		TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWEA));	//受信開始
	}
	else
	{
		TWCR = ((1<<TWINT) | (1<<TWEN));
	}

	while (!(TWCR & (1<<TWINT)));	//受信完了待機
	
	_ret = TWDR;

	return _ret;
}

void 
F_I2c_stop ()
{
	TWCR = ((1<<TWINT) | (1<<TWSTO) | (1<<TWEN));		//停止条件
	_delay_ms(5);
}

#endif

