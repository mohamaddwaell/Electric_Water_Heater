/*
 * KEYPAD_PROGRAM.c
 *
 * Created: 08-Feb-24 1:52:31 PM
 *  Author: Lenovo
 */ 
#include "KEYPAD_INTERFACE.h"
#include "DIO_INTERFACE.h"
#include "STD_TYPES.h"

void KEYPAD_INIT()
{
	DIO_setPinDir(KEYPAD_ROW0, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW1, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW2, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW3, DIO_INPUT);
	
	DIO_setPinDir(KEYPAD_COL0, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL1, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL2, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL3, DIO_OUTPUT);
	
	DIO_setPinPullup(KEYPAD_ROW0);
	DIO_setPinPullup(KEYPAD_ROW1);
	DIO_setPinPullup(KEYPAD_ROW2);
	DIO_setPinPullup(KEYPAD_ROW3);
	
	
}



u8 KEYPAD_READ()
{
	DIO_setPinValue(KEYPAD_COL0, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_COL0_ROW0;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_COL0_ROW1;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_COL0_ROW2;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_COL0_ROW3;
	}
	
	
	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_COL1_ROW0;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_COL1_ROW1;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_COL1_ROW2;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_COL1_ROW3;
	}
	
	
	
	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_COL2_ROW0;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_COL2_ROW1;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_COL2_ROW2;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_COL2_ROW3;
	}
	

	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_LOW);
	
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_COL3_ROW0;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_COL3_ROW1;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_COL3_ROW2;
	}
	
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_COL3_ROW3;
	}
	
	return KEYPAD_UNPRESSED;
	
}