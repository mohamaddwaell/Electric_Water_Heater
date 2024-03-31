/*
 * TIMER0_INTERFACE.h
 *
 * Created: 19-Feb-24 12:31:55 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "STD_TYPES.h"

#define TCCR0 *(volatile u8*)0x53
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

#define  TCNT0 *(volatile u8*)0x52

#define  OCR0 *(volatile u8*)0x5C

#define TIMSK 		*((volatile u8*)0x59)
#define OCIE0		1
#define TOIE0		0


#define TIMER0_CLK_DIV_1			0
#define TIMER0_CLK_DIV_8			1
#define TIMER0_CLK_DIV_64			2
#define TIMER0_CLK_DIV_256			3
#define TIMER0_CLK_DIV_1024			4
#define TIMER0_CLK_EXTERNAL_FALLING	5
#define TIMER0_CLK_EXTERNAL_RISING	6

#define OC0_DISCONNECTED 0
#define OC0_TOGGLE		 1
#define OC0_CLEAR		 2
#define OC0_SET			 3

#define ocPinMode        OC0_DISCONNECTED


//pwm
#define PWM_NON_INVERTING 0
#define PWM_INVERTING 1

#define PWM_MODE PWM_NON_INVERTING

#define PWM_FREQUENCY_62500  0 //1
#define PWM_FREQUENCY_7812   1 //8
#define PWM_FREQUENCY_976    2 //64
#define PWM_FREQUENCY_244    3 //256
#define PWM_FREQUENCY_61     4 //1024



void TIMER0_initNormalMode();

void TIMER0_start(u8 prescaler);
                
void TIMER0_setCallback( void (*APP_func)() );

void TIMER0_stop();

void TIMER0_setPreload(u8 ticks);

u8 TIMER0_readTimer();


//ctc

void TIMER0_initCTCMode();

void TIMER0_setOCR(u8 num);

void TIMER0_setCallbackCTC( void (*APP_func)() );

//PWM

void TIMER0_initPWMMode();

void TIMER0_setDuty(u8 duty);

void TIMER0_setFrequency(u8 pwm_frequency);



#endif /* TIMER0_INTERFACE_H_ */