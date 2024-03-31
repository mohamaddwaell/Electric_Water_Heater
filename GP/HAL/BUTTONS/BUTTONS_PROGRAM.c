

#include "BUTTONS_INTERFACE.h"

void BUTTONS_init()
{
	DIO_setPinDir(BUTTON_ON_OFF,DIO_OUTPUT);  // on/off button
	DIO_setPinDir(BUTTON_UP,DIO_OUTPUT);  // up button
	DIO_setPinDir(BUTTON_DOWN,DIO_OUTPUT);  // down button	
}

