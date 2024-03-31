/*
 * ADC_PROGRAM.c
 *
 * Created: 13-Feb-24 6:28:32 PM
 *  Author: Lenovo
 */ 

#include "BIT_MATH.h"

#include "ADC_INTERFACE.h"

void ADC_init()
{
	//set VCC
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	
	//pre scaler
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	//enable
	SET_BIT(ADCSRA,ADEN);
}


u16 ADC_read(u8 ch)   //return digital
{
	if(ch == ADC0)
	{
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
        CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	
	else if(ch == ADC1)
	{
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	
	else if(ch == ADC2)
	{
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ch == ADC3)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ch == ADC4)
	{
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	
	
	SET_BIT(ADCSRA,ADSC);
	while( GET_BIT(ADCSRA,ADSC) == 1);
	
	return ADCLH;
}


f32 ADC_convertAnalog(u16 digitalValue)  //return analog
{
	return (digitalValue * (5.0 / 1024));
}


