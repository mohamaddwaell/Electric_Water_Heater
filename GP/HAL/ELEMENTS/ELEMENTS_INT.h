

#ifndef FANANDHEATER_INT_H_
#define FANANDHEATER_INT_H_

#include "DIO_INTERFACE.h"

#define HEATER DIO_PINB7
#define FAN DIO_PINB6

#define HEATER_ON DIO_setPinValue(HEATER,DIO_HIGH);
#define HEATER_OFF DIO_setPinValue(HEATER,DIO_LOW);

#define FAN_ON DIO_setPinValue(FAN,DIO_HIGH);
#define FAN_OFF DIO_setPinValue(FAN,DIO_LOW);

void ELEMENTS_init();



#endif /* FANANDHEATER_INT_H_ */