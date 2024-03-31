/*
 * WDT_INTERFACE.h
 *
 * Created: 26-Feb-24 9:23:38 PM
 *  Author: Lenovo
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#include "STD_TYPES.h"

#define WDTCR (*(volatile u8*)0x41)

#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDTOE 4	

#define WDT_TIME_16_ms 0
#define WDT_TIME_32_ms 1
#define WDT_TIME_65_ms 2
#define WDT_TIME_130_ms 3
#define WDT_TIME_260_ms 4
#define WDT_TIME_520_ms 5
#define WDT_TIME_1_s 6
#define WDT_TIME_2_s 7


void WDT_start(u8 time);

void WDT_stop();



#endif /* WDT_INTERFACE_H_ */