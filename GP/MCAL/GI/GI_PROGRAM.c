/*
 * GI_PROGRAM.c
 *
 * Created: 09-Feb-24 2:02:54 PM
 *  Author: Lenovo
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_INTERFACE.h"

void GI_enable()
{
	SET_BIT(SREG, I);
}

void GI_disable()
{
	CLEAR_BIT(SREG , I);
}