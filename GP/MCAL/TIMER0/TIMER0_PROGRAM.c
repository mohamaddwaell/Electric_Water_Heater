/*
 * TIMER0_PROGRAM.c
 *
 * Created: 19-Feb-24 12:32:14 PM
 *  Author: Lenovo
 */ 
#include "TIMER0_INTERFACE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


void TIMER0_initNormalMode()
{
	//normal mode
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	
	//enable interrupt(overflow)
	SET_BIT(TIMSK,TOIE0);
}

void TIMER0_start(u8 prescaler)
{
		if(prescaler == TIMER0_CLK_DIV_1)
		{
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_DIV_8)
		{
			CLEAR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_DIV_64)
		{
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_DIV_256)
		{
			CLEAR_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_DIV_1024)
		{
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_EXTERNAL_FALLING)
		{
			CLEAR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		else if(prescaler == TIMER0_CLK_EXTERNAL_RISING)
		{
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		
}


void TIMER0_stop()
{
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}






void (*OV_ptr)();

void TIMER0_setCallback( void (*APP_func)() )
{
	OV_ptr = APP_func;
}


//ISR
void __vector_11(void) __attribute__((signal,used));   // 12 in data sheet but we start from 0 not 1, so 12-1=11
void __vector_11(void)
{
	//toggleLed();
	OV_ptr();
}

void TIMER0_setPreload(u8 ticks)
{
	TCNT0 = ticks;
}

u8 TIMER0_readTimer()
{
	return TCNT0;
}

void TIMER0_initCTCMode()
{
	//force bit
	SET_BIT(TCCR0, FOC0);
	
	//CTC mode
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	
	#if(ocPinMode == OC0_DISCONNECTED)
	{
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
	}
	#elif(ocPinMode == OC0_TOGGLE)
	{
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
	}
	#elif(ocPinMode == OC0_CLEAR)
	{
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	#elif(ocPinMode == OC0_SET)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	#endif
	
	//enable interrupt
	SET_BIT(TIMSK,OCIE0);
	
}

void TIMER0_setOCR(u8 num)
{
	OCR0 = num;
}

void (*CTC_ptr)();

void TIMER0_setCallbackCTC( void (*APP_func)() )
{
	CTC_ptr = APP_func;
}

//ISR
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	//toggleLed();
	CTC_ptr();
	
	
}



void TIMER0_initPWMMode()
{
	//force bit
	SET_BIT(TCCR0, FOC0);
	
	//PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	#if(PWM_MODE == PWM_NON_INVERTING)
	{
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
	
	#elif(PWM_MODE == PWM_INVERTING)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#endif
}


void TIMER0_setDuty(u8 duty)
{
	#if(PWM_MODE == PWM_NON_INVERTING)
	{
		OCR0 = ( duty * 256 / 100 )-1;
	}
	
	#elif(PWM_MODE == PWM_INVERTING)
	{
		
	}
	#endif
}

void TIMER0_setFrequency(u8 pwm_frequency)
{
	if(pwm_frequency == PWM_FREQUENCY_62500)
	{
		TIMER0_start(TIMER0_CLK_DIV_1);
	}
	else if (pwm_frequency == PWM_FREQUENCY_7812)
	{
		TIMER0_start(TIMER0_CLK_DIV_8);
	}
	else if (pwm_frequency == PWM_FREQUENCY_976)
	{
		TIMER0_start(TIMER0_CLK_DIV_64);
	}
	else if (pwm_frequency == PWM_FREQUENCY_244)
	{
		TIMER0_start(TIMER0_CLK_DIV_256);
	}
	else if (pwm_frequency == PWM_FREQUENCY_61)
	{
		TIMER0_start(TIMER0_CLK_DIV_1024);
	}
}