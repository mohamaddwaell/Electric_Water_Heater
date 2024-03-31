/*
 * DIO_PROGRAM.c
 *
 * Created: 29-Jan-24 2:36:59 PM
 *  Author: Lenovo
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"

void DIO_setPinValue(u8 PinNum,u8 level)
{
	if(PinNum>=0 && PinNum<=7)
	{
		if (level ==DIO_HIGH)
		{
			SET_BIT(PORTA,PinNum);
		}
		else if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTA,PinNum);
		}
	}
	else if (PinNum>=8 && PinNum<=15)
	{
		PinNum=PinNum-8;
		if (level ==DIO_HIGH)
		{
			SET_BIT(PORTB,PinNum);
		}
		else if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTB,PinNum);
		}
	}
	else if (PinNum>=16 && PinNum<=23)
	{
		PinNum=PinNum-16;
		if (level ==DIO_HIGH)
		{
			SET_BIT(PORTC,PinNum);
		}
		else if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTC,PinNum);
		}
		
	}
	else if (PinNum>=24 && PinNum<=31)
	{
		PinNum=PinNum-24;
		if (level ==DIO_HIGH)
		{
			SET_BIT(PORTD,PinNum);
		}
		else if (level == DIO_LOW)
		{
			CLEAR_BIT(PORTD,PinNum);
		}
	}
}


void DIO_setPinDir(u8 PinNum,u8 state)
{
	if(PinNum>=0 && PinNum<=7)
	{
		if (state ==DIO_OUTPUT)
		{
			SET_BIT(DDRA,PinNum);
		}
		else if (state == DIO_INPUT)
		{
			CLEAR_BIT(DDRA,PinNum);
		}
	}
	else if (PinNum>=8 && PinNum<=15)
	{
		PinNum=PinNum-8;
		if (state ==DIO_OUTPUT)
		{
			SET_BIT(DDRB,PinNum);
		}
		else if (state == DIO_INPUT)
		{
			CLEAR_BIT(DDRB,PinNum);
		}
	}
	else if (PinNum>=16 && PinNum<=23)
	{
		PinNum=PinNum-16;
		if (state ==DIO_OUTPUT)
		{
			SET_BIT(DDRC,PinNum);
		}
		else if (state == DIO_INPUT)
		{
			CLEAR_BIT(DDRC,PinNum);
		}
		
	}
	else if (PinNum>=24 && PinNum<=31)
	{
		PinNum=PinNum-24;
		if (state ==DIO_OUTPUT)
		{
			SET_BIT(DDRD,PinNum);
		}
		else if (state == DIO_INPUT)
		{
			CLEAR_BIT(DDRD,PinNum);
		}
	}
}


u8 DIO_readPinValue(u8 PinNum)
{
		if(PinNum>=0 && PinNum<=7)
		{
			return GET_BIT(PINA,PinNum);
		}
		else if(PinNum>=8 && PinNum<=15)
		{
			PinNum=PinNum-8;
			return GET_BIT(PINB,PinNum);
		}
		else if(PinNum>=16 && PinNum<=23)
		{
			PinNum=PinNum-16;
			return GET_BIT(PINC,PinNum);
		}
		else if(PinNum>=24 && PinNum<=31)
		{
			PinNum=PinNum-24;
			return GET_BIT(PIND,PinNum);
		}
}


void DIO_setPinPullup(u8 PinNum)
{
	DIO_setPinValue(PinNum,DIO_HIGH);
}

void DIO_togglePin(u8 pinNum)
{
	if(DIO_readPinValue(pinNum) ==DIO_HIGH)
	{
		DIO_setPinValue(pinNum, DIO_LOW);
	}
	else if(DIO_readPinValue(pinNum) ==DIO_LOW)
	{
		DIO_setPinValue(pinNum, DIO_HIGH);
	}
}
