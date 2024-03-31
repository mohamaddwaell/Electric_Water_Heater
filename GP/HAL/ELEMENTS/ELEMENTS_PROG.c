

#include "ELEMENTS_INT.h"


void ELEMENTS_init()
{
	DIO_setPinDir(HEATER,DIO_OUTPUT);
	DIO_setPinDir(FAN,DIO_OUTPUT);
}

