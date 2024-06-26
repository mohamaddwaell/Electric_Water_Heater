#include "DIO_INTERFACE.h"
#include "STD_TYPES.h"


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define  KEYPAD_COL0 DIO_PINC3
#define  KEYPAD_COL1 DIO_PINC4
#define  KEYPAD_COL2 DIO_PINC5
#define  KEYPAD_COL3 DIO_PINC6

#define KEYPAD_ROW0 DIO_PINB4
#define KEYPAD_ROW1 DIO_PINB5
#define KEYPAD_ROW2 DIO_PINB6
#define KEYPAD_ROW3 DIO_PINB7

#define KEYPAD_COL0_ROW0 '7'
#define KEYPAD_COL1_ROW0 '8'
#define KEYPAD_COL2_ROW0 '9'
#define KEYPAD_COL3_ROW0 '/'

#define KEYPAD_COL0_ROW1 '4'
#define KEYPAD_COL1_ROW1 '5'
#define KEYPAD_COL2_ROW1 '6'
#define KEYPAD_COL3_ROW1 '*'

#define KEYPAD_COL0_ROW2 '1'
#define KEYPAD_COL1_ROW2 '2'
#define KEYPAD_COL2_ROW2 '3'
#define KEYPAD_COL3_ROW2 '-'

#define KEYPAD_COL0_ROW3 'C'
#define KEYPAD_COL1_ROW3 '0'
#define KEYPAD_COL2_ROW3 '='
#define KEYPAD_COL3_ROW3 '+'

#define KEYPAD_UNPRESSED 'x'



void KEYPAD_INIT();

u8 KEYPAD_READ();


#endif /* KEYPAD_INTERFACE_H_ */