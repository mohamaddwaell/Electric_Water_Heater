/*
 * LCD_INTERFACE.h
 *
 * Created: 02-Feb-24 4:32:16 PM
 *  Author: Lenovo
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "DIO_INTERFACE.h"
#include "STD_TYPES.h"



#define LCD_E DIO_PINB3
#define LCD_RW DIO_PINB4
#define LCD_RS DIO_PINB5

#define LCD_D0 DIO_PINA1
#define LCD_D1 DIO_PINA2
#define LCD_D2 DIO_PINA3
#define LCD_D3 DIO_PINA4
#define LCD_D4 DIO_PINA5
#define LCD_D5 DIO_PINA6
#define LCD_D6 DIO_PINA7
#define LCD_D7 DIO_PINB2

#define LCD_MODE 4

void LCD_init();

void LCD_writeChar(u8 data);

void LCD_writeString(u8* str);

void LCD_writeNum(s32 num);

void LCD_clearDis();

void LCD_goto(u8 x,u8 line);

void LCD_writeCmd(u8 data);








#endif /* LCD_INTERFACE_H_ */