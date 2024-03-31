/*
 * LCD_PROGRAM.c
 *
 * Created: 02-Feb-24 4:32:32 PM
 *  Author: Lenovo
 */ 

#define F_CPU 16000000
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_INTERFACE.h"

#include "LCD_INTERFACE.h"


void LCD_init()
{
	#if LCD_MODE == 4
	
	DIO_setPinDir(LCD_RS,DIO_OUTPUT);
	DIO_setPinDir(LCD_RW,DIO_OUTPUT);
	DIO_setPinDir(LCD_E,DIO_OUTPUT);
	
	DIO_setPinDir(LCD_D4,DIO_OUTPUT);
	DIO_setPinDir(LCD_D5,DIO_OUTPUT);
	DIO_setPinDir(LCD_D6,DIO_OUTPUT);
	DIO_setPinDir(LCD_D7,DIO_OUTPUT);
	
	_delay_ms(50);
	LCD_writeCmd(0b00000010);
	LCD_writeCmd(0b00101000);
	_delay_ms(1);
	LCD_writeCmd(0b00001110);
	_delay_ms(1);
	LCD_writeCmd(0b00000001);
	_delay_ms(5);
	LCD_writeCmd(0b00000110);
	
	
	
	#elif LCD_MODE == 8
	
	DIO_setPinDir(LCD_RS,DIO_OUTPUT);
	DIO_setPinDir(LCD_RW,DIO_OUTPUT);
	DIO_setPinDir(LCD_E,DIO_OUTPUT);
	
	DIO_setPinDir(LCD_D0,DIO_OUTPUT);
	DIO_setPinDir(LCD_D1,DIO_OUTPUT);
	DIO_setPinDir(LCD_D2,DIO_OUTPUT);
	DIO_setPinDir(LCD_D3,DIO_OUTPUT);
	DIO_setPinDir(LCD_D4,DIO_OUTPUT);
	DIO_setPinDir(LCD_D5,DIO_OUTPUT);
	DIO_setPinDir(LCD_D6,DIO_OUTPUT);
	DIO_setPinDir(LCD_D7,DIO_OUTPUT);
	
	_delay_ms(50);
	LCD_writeCmd(0b00111000);
	_delay_ms(1);
	LCD_writeCmd(0b00001110);
	_delay_ms(1);
	LCD_writeCmd(0b00000001);
	_delay_ms(5);
	LCD_writeCmd(0b00000110);
	
	
	
	#endif
	
	
}


static void LCD_sendData(u8 data)
{
	#if LCD_MODE == 4
	
	
	DIO_setPinValue(LCD_D4,GET_BIT(data,4));
	DIO_setPinValue(LCD_D5,GET_BIT(data,5));
	DIO_setPinValue(LCD_D6,GET_BIT(data,6));
	DIO_setPinValue(LCD_D7,GET_BIT(data,7));
	
	DIO_setPinValue(LCD_E,DIO_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E,DIO_LOW);	
	
	DIO_setPinValue(LCD_D4,GET_BIT(data,0));
	DIO_setPinValue(LCD_D5,GET_BIT(data,1));
	DIO_setPinValue(LCD_D6,GET_BIT(data,2));
	DIO_setPinValue(LCD_D7,GET_BIT(data,3));
	
	DIO_setPinValue(LCD_E,DIO_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E,DIO_LOW);
	
	#elif LCD_MODE == 8
	
	DIO_setPinValue(LCD_D0,GET_BIT(data,0));
	DIO_setPinValue(LCD_D1,GET_BIT(data,1));
	DIO_setPinValue(LCD_D2,GET_BIT(data,2));
	DIO_setPinValue(LCD_D3,GET_BIT(data,3));
	DIO_setPinValue(LCD_D4,GET_BIT(data,4));
	DIO_setPinValue(LCD_D5,GET_BIT(data,5));
	DIO_setPinValue(LCD_D6,GET_BIT(data,6));
	DIO_setPinValue(LCD_D7,GET_BIT(data,7));
	
	DIO_setPinValue(LCD_E,DIO_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E,DIO_LOW);
	
	#endif
}


void LCD_writeCmd(u8 data)
{
	DIO_setPinValue(LCD_RS,DIO_LOW);
	DIO_setPinValue(LCD_RW,DIO_LOW);
	LCD_sendData(data);
	
}

void LCD_writeChar(u8 data)
{
	DIO_setPinValue(LCD_RS,DIO_HIGH);
	DIO_setPinValue(LCD_RW,DIO_LOW);
	LCD_sendData(data);
	
}

void LCD_writeString(u8* str)
{
	u8 i=0;
	while(str[i] != '\0' )
	{
		LCD_writeChar(str[i]);
		i++;
	}
}


void LCD_clearDis()
{
	LCD_writeCmd(0b00000001);
	_delay_ms(1);
}


void LCD_writeNum(s32 num)
{
	if(num == 0)
	{
		LCD_writeChar('0');
		return;
	}
	
	if(num<0)
	{
		LCD_writeChar('-');
		num = num * (-1);
	}
	u8 x=0,i=0;
	u8 arr[16];
	while( num != 0)
	{
		x=num % 10;
		arr[i] = (x+48);
		i++;
		num = num /10;
	}
	
	s8 k;
	for(k=i-1 ;k>=0 ;k--)
	{
		LCD_writeChar(arr[k]);
	} 
	
}


void LCD_goto(u8 x,u8 line)
{
	if(line == 1)
	{
		LCD_writeCmd(10000000 + x);
	}
	
	else if(line == 2)
	{
		LCD_writeCmd(10000000 + x + 0x40);
	}
		
}