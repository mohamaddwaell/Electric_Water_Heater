


#include "TIMER0_INTERFACE.h"
#include "GI_INTERFACE.h"
#include "RTOS_INTERFACE.h"



task_t arryTasks[RTOS_TASK_NUM];


void RTOS_createTask(u16 userperiodicity, void (*userPtrFunc)(), u8 periority)
	{
		arryTasks[periority].periodicity = userperiodicity;
		arryTasks[periority].ptrFunc = userPtrFunc;
	}

void RTOS_start()
	{
		GI_enable();
		
		TIMER0_initCTCMode();
		TIMER0_setOCR(249);//1 msec
		TIMER0_setCallbackCTC(RTOS_sechdeuler);
		TIMER0_start(TIMER0_CLK_DIV_64);
	}

//ISR -> ctc mode
void RTOS_sechdeuler()
	{
		static u16 sysTick =0;
		sysTick++;
		
		for(u8 i=0; i<RTOS_TASK_NUM; i++)
		{
			if(sysTick % arryTasks[i].periodicity == 0)
			{
				arryTasks[i].ptrFunc();
			}
		}
	}