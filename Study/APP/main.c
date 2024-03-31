
/*
 * Study.c
 *
 * Created: 29-Jan-24 1:40:11 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "GI_INTERFACE.h"
#include "EXT_INTERFACE.h"
#include "ADC_INTERFACE.h"
#include "TIMER0_INTERFACE.h"
#include "I2C_INTERFACE.h"
#include "EEPROM_INTERFACE.h"
#include "BUTTONS_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "ELEMENTS_INT.h"
#include "TIMER1_INTERFACE.h"

#define F_CPU 16000000
#include <util/delay.h>

#define MAX_TEMP 75
#define MIN_TEMP 35
#define STEP_TEMP 5 

#define OFF 0
#define ON 1
#define READY 2


u16 actual_temp;
f32 actual_temp_analog;
u8 actual_temp_celesius;
u8 on_off_mode = OFF;
u16 desired_temp;
u8 button_mode = first_push;
u8 lcd_flag = OFF;
u16 counter1= 0; 
u8 TIMER1_flag = OFF;
u8 led_flag = OFF;
u8 arr[10];
u8 ADC_counter = 0;

void callbackTimer0()
{
	static u16 counter=0;
	counter++;
	//every 100 msec
	if(counter % 100 == 0)
	{
		counter=0;
		if(ADC_counter < 10)
		{
			arr[ADC_counter] = ADC_read(ADC0);
			ADC_counter++;
		}	
	}
}

void callbackTimer1()
{
	counter1++;
	//every 5 sec
	if( TIMER1_flag == ON && counter1 == 5000 )
	{
		button_mode = first_push;
		counter1=0;
		TIMER1_flag = OFF;	
	}
	if (led_flag == ON)
	{
		if(counter1 % 1000 == 0)  //toggle led every 1 sec
		{
			LED_toggle;
		}
	}
}

void INT0_func()
{	
	if(on_off_mode == ON)
	{
		on_off_mode = OFF;
	}
	else if(on_off_mode == OFF)
	{
		lcd_flag = ON;
		on_off_mode = ON;
	}
}

int main(void)
{
	BUTTONS_init();
	GI_enable();
	EXT0_init(EXT_RISING);
	EXT_setCallbackInt0(INT0_func);
	LCD_init();
	EEPROM_init();
	ADC_init();
	LED_init;
	ELEMENTS_init();
	TIMER0_initCTCMode();
	TIMER0_setCallbackCTC(callbackTimer0);
	TIMER0_setOCR(249);
	TIMER0_start(TIMER0_CLK_DIV_64);
	TIMER1_initCTCMode();
	TIMER1_setCallbackCTC(callbackTimer1);
	TIMER1_setOCR(249);
	TIMER1_start(TIMER1_CLK_DIV_64);
	
	
	if(EEPROM_readData(0x50) == 255)
	{
		desired_temp = 60;
	}
	else
	{
		desired_temp = EEPROM_readData(0x50);
	}

		
	while (1)
	{
//////////////////////////////////////////////////////////////////////// LCD Flag
		
		if(on_off_mode == ON )  //ON mode
		{
			if(lcd_flag == ON)			
			{
				LCD_goto(0,1);
				LCD_writeString("Actual Temp:");
				LCD_goto(0,2);
				LCD_writeString("Desired Temp:");
				LCD_writeNum(desired_temp);
				lcd_flag = OFF;
			}	
			
///////////////////////////////////////////////////////////////////////	BUTTON UP	
		
		if(DIO_readPinValue(BUTTON_UP) == DIO_HIGH)
		{
			while(DIO_readPinValue(BUTTON_UP) == DIO_HIGH);
			
			TIMER1_flag = ON;
			counter1 = 0;
			
			if(button_mode == first_push)
			{
				LCD_goto(0,2);
				LCD_writeString("TempSetMode ");
				button_mode = not_first_push;
			}
			else if(button_mode == not_first_push)
			{	
				if(desired_temp + STEP_TEMP <= MAX_TEMP)
				{
					desired_temp = desired_temp + STEP_TEMP;
					EEPROM_writeData(desired_temp,0x50);
					LCD_goto(13,2);
					LCD_writeNum(desired_temp);
				}
				else if(desired_temp + STEP_TEMP > MAX_TEMP)
				{
					desired_temp = MAX_TEMP;
					EEPROM_writeData(desired_temp,0x50);
					LCD_goto(13,2);
					LCD_writeNum(desired_temp);
				}
			}
		}
		
///////////////////////////////////////////////////////////////////BUTTON DOWN

		if(DIO_readPinValue(BUTTON_DOWN) == DIO_HIGH)
		{
			while(DIO_readPinValue(BUTTON_DOWN) == DIO_HIGH);
			
			TIMER1_flag = ON;
			counter1 = 0;
			
			if( button_mode == first_push)
			{
				LCD_goto(0,2);
				LCD_writeString("TempSetMode ");
				button_mode = not_first_push;
			}
			else if( button_mode == not_first_push)
			{
				if(desired_temp - STEP_TEMP >= MIN_TEMP)
				{
					desired_temp = desired_temp - STEP_TEMP;
					EEPROM_writeData(desired_temp,0x50);
					LCD_goto(13,2);
					LCD_writeNum(desired_temp);
				}
				else if(desired_temp - STEP_TEMP < MIN_TEMP)
				{
					desired_temp = MIN_TEMP;
					EEPROM_writeData(desired_temp,0x50);
					LCD_goto(13,2);
					LCD_writeNum(desired_temp);
				}
			}	
		}		
///////////////////////////////////////////////////////////////////TEMPERATURE SET MODE OFF(after 5 sec of buttons unpressed)

if(TIMER1_flag == OFF)
{
	LCD_goto(0,2);
	LCD_writeString("Desired Temp:");
	TIMER1_flag = READY;
}

//////////////////////////////////////////////////////////////////////////////////////	ADC Reading(10 times)

if(ADC_counter == 10)
{
	actual_temp = 0;
	for (ADC_counter =0 ; ADC_counter < 10 ; ADC_counter++)
	{
		actual_temp = actual_temp+arr[ADC_counter];
	}
	actual_temp = actual_temp / 10;
	ADC_counter = 0;
}
		
///////////////////////////////////////////////////////////////	LM35		
	   
	  actual_temp_analog = ADC_convertAnalog(actual_temp);
	  actual_temp_celesius = 100 * actual_temp_analog;
	  LCD_goto(12,1);
	  LCD_writeNum(actual_temp_celesius);
	       
//////////////////////////////////////////////////////////////	FAN/HEATER	

			if(actual_temp_celesius < (desired_temp - 4) )
			{
				HEATER_ON;
				FAN_OFF;
				led_flag = ON;
				
			}
			else if (actual_temp_celesius > (desired_temp + 4) )
			{
				HEATER_OFF;
				led_flag = OFF;
				FAN_ON;
				LED_ON;
				
			}
			else
			{
				HEATER_OFF;
				led_flag = OFF;
				FAN_OFF;
				LED_OFF;
			}		
			
		} // ON mode
		
/////////////////////////////////////////////////////////////////////////////// OFF mode
		
		else if(on_off_mode == OFF)
		{
			LCD_clearDis();
			LED_OFF;
			HEATER_OFF;
			FAN_OFF;
			TIMER1_flag = OFF;
			button_mode = first_push;
		}
			
///////////////////////////////////////////////////////////////////////////////////////

			
			
	}
}



