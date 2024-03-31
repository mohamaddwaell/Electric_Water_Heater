


#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

#include "STD_TYPES.h"

#define RTOS_TASK_NUM 3


typedef struct task
{
	u16 periodicity;
	void (*ptrFunc)();
}task_t;



void RTOS_createTask(u16 userperiodicity, void (*userPtrFunc)(), u8 periority);

void RTOS_start();

static void RTOS_sechdeuler();


#endif /* RTOS_INTERFACE_H_ */