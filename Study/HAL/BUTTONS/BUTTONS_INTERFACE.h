

#ifndef BUTTONS_INTERFACE_H_
#define BUTTONS_INTERFACE_H_

#include "DIO_INTERFACE.h"

#define BUTTON_ON_OFF DIO_PIND5
#define BUTTON_UP DIO_PIND6
#define BUTTON_DOWN DIO_PIND7

#define first_push 0
#define not_first_push 1

void BUTTONS_init();

#endif /* BUTTONS_INTERFACE_H_ */