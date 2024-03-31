/*
 * TIMER1_PROGRAM.c
 *
 * Created: 23-Feb-24 1:43:53 PM
 *  Author: Lenovo
 */ 
#include "TIMER1_INTERFACE.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"

void TIMER1_initFastPWMMode14()
{
	//force bit
	CLEAR_BIT(TCCR1A,FOC1A);
	//mode 14
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	 	
	#if(TIMER1_PWM_MODE == TIMER1_PWM_NON_INVERTING)
	{
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	}
	#elif(TIMER1_PWM_MODE == TIMER1_PWM_INVERTING)
	{
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	}
	#endif	 
}

void TIMER1_setDuty(u8 duty)
{
	#if(TIMER1_PWM_MODE == TIMER1_PWM_NON_INVERTING)
	{
		OCR1A = (duty*(ICR1+1)/100) -1;
	}
	#elif(TIMER1_PWM_MODE == TIMER1_PWM_INVERTING)
	{
		
	}
	#endif
}

void TIMER1_setFrequency(u16 pwm_frequency)
{
	//ICR1 = 4999;//-> 50 Hz
	ICR1 = (16000000/(64.0*pwm_frequency))-1;
	
	// select prescaler 64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}

/////////////////CTC

void TIMER1_initCTCMode()
{
    TCCR1A = 0; // Clear TCCR1A register
	TCCR1B = 0; // Clear TCCR1B register
	//force bit
	//CLEAR_BIT(TCCR1A,FOC1A);
	//mode 4
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);
	//enable interrupt
	SET_BIT(TIMSK,OCIE1A);
}

void TIMER1_setOCR(u16 num)
{
	OCR1A = num;
}


void TIMER1_start(u8 prescaler)
{
	if(prescaler == TIMER1_CLK_DIV_1)
	{
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_DIV_8)
	{
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_DIV_64)
	{
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_DIV_256)
	{
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_DIV_1024)
	{
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_EXTERNAL_FALLING)
	{
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	}
	else if(prescaler == TIMER1_CLK_EXTERNAL_RISING)
	{
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	}
	
}

void (*T1_CTC_ptr)();

void TIMER1_setCallbackCTC( void (*APP_func)() )
{
	T1_CTC_ptr = APP_func;
}

//ISR
void __vector_7(void) __attribute__((signal,used));  
void __vector_7(void)
{
	T1_CTC_ptr();	
}

void TIMER1_stop()
{
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}