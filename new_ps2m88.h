//////////////////////////////
//new_ps2m88.h				//
//////////////////////////////
#include<avr/io.h>
#include<util/delay.h>

//////////////////////////////
// SEL PORT init
//////////////////////////////
#define DDR_SEL DDRB
#define PORT_SEL PORTB
#define PIN_SEL PINB
#define SEL PB1

//////////////////////////////
// ACK PORT init
//////////////////////////////
#define DDR_ACK DDRB
#define PORT_ACK PORTB
#define PIN_ACK PINB
#define ACK PB2

/********************************************/

void PS2_init(void);
void READ_DATA_AND_VIBRATE_EX(int *px,int y,int z);

/*******************************************/

void spi_init(void);

int READ_DATA(void);
void CONFIG_MODE_ENTER(void);
void SET_MODE_AND_LOCK(void);
void VIBRATION_ENABLE(void);
void CONFIG_MODE_EXIT(void);
void PRESSURE_ENABLE(void);
void PRES_TRANS_START(void);

int data_trans(int x);
void data_out(int x);
void data_in(int *px);
void data_in_vibrate(int *px,int y,int z);

/*******************************************/

void PS2_init(void)
{
	int res = 0;

	DDR_SEL |= (1<<SEL);
	DDR_ACK |= (1<<ACK);

	PORT_SEL |= (1<<SEL);
	PORT_ACK |= (1<<ACK);

	_delay_ms(10);

	spi_init();

	//while(1)
	//{
		res = READ_DATA();
	//	if((res == 0x41) || ( res == 0x73))
	//		break;
	//}

	CONFIG_MODE_ENTER();
	SET_MODE_AND_LOCK();
	//SET_MODE_AND_LOCK();
	VIBRATION_ENABLE();
	//VIBRATION_ENABLE();
	CONFIG_MODE_EXIT();

	CONFIG_MODE_ENTER();
	//CONFIG_MODE_ENTER();
	PRESSURE_ENABLE();
	//PRESSURE_ENABLE();
	PRES_TRANS_START();
	//PRES_TRANS_START();
	CONFIG_MODE_EXIT();
}

void spi_init(void)
{
	SPCR=((1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA)|(1<<SPR1)|(1<<SPR0));
	//SPSR=(1<<SPI2X);
}

int READ_DATA(void)
{
	int res=0;

	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	res = data_trans(0x42);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;

	return res;
}

void CONFIG_MODE_ENTER(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x43);
	data_out(0x00);
	data_out(0x01);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void SET_MODE_AND_LOCK(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x44);
	data_out(0x00);
	data_out(0x01);
	data_out(0x03);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void VIBRATION_ENABLE(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x4d);
	data_out(0x00);
	data_out(0x00);
	data_out(0x01);
	data_out(0xff);
	data_out(0xff);
	data_out(0xff);
	data_out(0xff);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void CONFIG_MODE_EXIT(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x43);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void PRESSURE_ENABLE(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x4f);
	data_out(0x00);
	data_out(0xff);
	data_out(0xff);
	data_out(0x03);
	data_out(0x00);
	data_out(0x00);
	data_out(0x00);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void PRES_TRANS_START(void)
{
	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);
	data_out(0x43);
	data_out(0x00);
	data_out(0x00);
	data_out(0x5a);
	data_out(0x5a);
	data_out(0x5a);
	data_out(0x5a);
	data_out(0x5a);
	
	PORT_SEL |= (1<<SEL);

	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
}

void READ_DATA_AND_VIBRATE_EX(int *px,int y,int z)
{
	int i=0,res=0;
	
	start:

	for(i=0;i<18;i++)							//ƒf[ƒ^‚Ì‰Šú‰»
	{
		px[i]=0;
	}

	PORT_SEL &= ~(1<<SEL);
	TCNT0 = 99;
	TCCR0B = ((1<<CS02)|(1<<CS00));

	data_out(0x01);		
	data_out(0x42);
	res = data_trans(0x00);
	data_in_vibrate(px,y,z);
	data_in(px);
	
	PORT_SEL |= (1<<SEL);
	while(!(TIFR0&(1<<TOV0)));
	TIFR0|=(1<<TOV0);
	TCCR0B = 0;
	
	if(res != 0x5a)
	{
		goto start;
	}
}

int data_trans(int x)
{
	int temp;

	SPDR = x;
	while(!(SPSR&(1<<SPIF)));
	temp = SPIF;
	temp = SPDR;

	_delay_us(5);
	PORT_ACK &= ~(1<<ACK);
	_delay_us(5);
	PORT_ACK |= (1<<ACK);
	_delay_us(5);

	return temp;
}

void data_out(int x)
{
	int temp;

	SPDR = x;
	while(!(SPSR&(1<<SPIF)));
	temp = SPIF;
	temp = SPDR;

	_delay_us(5);
	PORT_ACK &= ~(1<<ACK);
	_delay_us(5);
	PORT_ACK |= (1<<ACK);
	_delay_us(5);
}

void data_in(int *px)
{
	int i,temp;

	for(i=2;i<18;i++)
	{
		SPDR = 0x00;
		while(!(SPSR&(1<<SPIF)));
		temp = SPIF;
		px[i]=SPDR;

		_delay_us(5);
		PORT_ACK &= ~(1<<ACK);
		_delay_us(5);	
		PORT_ACK |= (1<<ACK);
		_delay_us(5);
	}
}

void data_in_vibrate(int *px,int y,int z)
{
	int temp;

	SPDR = y;
	while(!(SPSR&(1<<SPIF)));
	temp = SPIF;
	px[0]=SPDR;

	_delay_us(5);
	PORT_ACK &= ~(1<<ACK);
	_delay_us(5);	
	PORT_ACK |= (1<<ACK);
	_delay_us(5);


	SPDR = z;
	while(!(SPSR&(1<<SPIF)));
	temp = SPIF;
	px[1]=SPDR;

	_delay_us(5);
	PORT_ACK &= ~(1<<ACK);
	_delay_us(5);	
	PORT_ACK |= (1<<ACK);
	_delay_us(5);
}
	

