


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "STD_TYPES.h"

#define MOTOR_LEFT	0
#define MOTOR_RIGHT	1

void MOTOR_init();

 void MOTOR_start(u8 duty, u8 dir);


#endif /* MOTOR_INTERFACE_H_ */