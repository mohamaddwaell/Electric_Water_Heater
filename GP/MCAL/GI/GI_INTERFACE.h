/*
 * GI_INTERFACE.h
 *
 * Created: 09-Feb-24 2:03:14 PM
 *  Author: Lenovo
 */ 


#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

#define SREG *(volatile u8*)0x5F
#define I 7

void GI_enable();
void GI_disable();



#endif /* GI_INTERFACE_H_ */