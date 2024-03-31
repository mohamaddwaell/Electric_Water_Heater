/*
 * EXT_INTERFACE.h
 *
 * Created: 09-Feb-24 2:13:58 PM
 *  Author: Lenovo
 */ 
#include "STD_TYPES.h"



#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

#define MCUCR *(volatile u8*)0x55
#define MCUCSR *(volatile u8*)0x54
#define GICR *(volatile u8*)0x5B

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define ISC2 6

#define INT0 6
#define INT1 7
#define INT2 5

#define EXT_LOW_LEVEL 0
#define EXT_ANY_LOGICAL 1
#define EXT_FALLING	2
#define EXT_RISING 3


void EXT0_init(u8 level);
void EXT1_init(u8 level);
void EXT2_init(u8 level);

void EXT_setCallbackInt1(void(*ptr)());
void EXT_setCallbackInt0(void(*ptr)());


#endif /* EXT_INTERFACE_H_ */