/*
 * EXT_PROGRAM.c
 *
 * Created: 09-Feb-24 2:14:15 PM
 *  Author: Lenovo
 */ 
#include "STD_TYPES.h"
#include "EXT_INTERFACE.h"
#include "BIT_MATH.h"

#include "DIO_INTERFACE.h"




void EXT0_init(u8 level)
{
	if(level == EXT_RISING)
	{
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
	}
	
	else if(level == EXT_FALLING)
	{
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
	}
	
	else if(level == EXT_LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
	}
	
	else if(level == EXT_ANY_LOGICAL)
	{
		SET_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
	}
	SET_BIT(GICR,INT0);
	
}


void EXT1_init(u8 level)
{
	if(level == EXT_RISING)
	{
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
	}
	
	else if(level == EXT_FALLING)
	{
		CLEAR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
	}
	
	else if(level == EXT_LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
	}
	
	else if(level == EXT_ANY_LOGICAL)
	{
		SET_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);
	}
	SET_BIT(GICR,INT1);
}


void EXT2_init(u8 level)
{
	if(level == EXT_RISING)
	{
		SET_BIT(MCUCSR,ISC2);
	}
	
	else if(level == EXT_FALLING)
	{
		CLEAR_BIT(MCUCSR,ISC2);
	}
	SET_BIT(GICR,INT2);
}



void (*INT1_ptr)();
void (*INT0_ptr)();

void EXT_setCallbackInt1(void(*ptr)())
{
	INT1_ptr=ptr;
}

void EXT_setCallbackInt0(void(*ptr)())
{
	INT0_ptr = ptr;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	INT0_ptr();
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	INT1_ptr();
}