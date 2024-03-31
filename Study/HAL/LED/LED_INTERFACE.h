


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "DIO_INTERFACE.h"
#define F_CPU 16000000
#include <util/delay.h>

#define LED_Heat_Element  DIO_PINC5

#define LED_init DIO_setPinDir(LED_Heat_Element,DIO_OUTPUT);

#define LED_ON	DIO_setPinValue(LED_Heat_Element,DIO_HIGH);

#define LED_OFF DIO_setPinValue(LED_Heat_Element,DIO_LOW);

#define  LED_toggle DIO_togglePin(LED_Heat_Element);






#endif /* LED_INTERFACE_H_ */