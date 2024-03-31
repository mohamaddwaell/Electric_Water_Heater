

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"


#define ADMUX *((volatile u8*)0x27)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA *((volatile u8*)0x26)
#define ADEN 7
#define ADSC 6
#define ADIF 4
#define ADPS2   2	//Prescaler
#define ADPS1   1	//Prescaler
#define ADPS0   0	//Prescaler

#define ADCH 				*((volatile u8*)0x25)//low bits only
#define ADCL 				*((volatile u8*)0x24)//high bits only
#define ADCLH				*((volatile u16*)0x24)//all bits..(u16)

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4


void ADC_init();

u16 ADC_read(u8 ch); //return digital

f32 ADC_convertAnalog(u16 digitalValue);  //return analog


#endif /* ADC_INTERFACE_H_ */