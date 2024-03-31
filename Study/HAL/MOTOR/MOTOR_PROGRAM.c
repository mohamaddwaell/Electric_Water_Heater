#include "DIO_INTERFACE.h"
#include "MOTOR_INTERFACE.h"
#include "TIMER0_INTERFACE.h"
#include "TIMER1_INTERFACE.h"

void MOTOR_init()
{
	DIO_setPinDir(DIO_PINC5,DIO_OUTPUT);
	DIO_setPinDir(DIO_PINC6,DIO_OUTPUT);
	TIMER1_initFastPWMMode14();
}

 static void MOTOR_setDir(u8 dir)
 {
	 if (dir == MOTOR_LEFT)
	 {
		 DIO_setPinValue(DIO_PINC5,DIO_LOW);
		 DIO_setPinValue(DIO_PINC6,DIO_HIGH);
	 }
	 else if(dir == MOTOR_RIGHT)
	 {
		 DIO_setPinValue(DIO_PINC5,DIO_HIGH);
		 DIO_setPinValue(DIO_PINC6,DIO_LOW);
	 }
 }
 
 static void MOTOR_setSpeed(u8 duty)
 {
	 TIMER1_setDuty(duty);
 }
 
 void MOTOR_start(u8 duty, u8 dir)
 {
	 TIMER1_setFrequency(1000);
	 MOTOR_setSpeed(duty);
	 MOTOR_setDir(dir);
 }