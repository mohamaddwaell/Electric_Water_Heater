

#include "WDT_INTERFACE.h"
#include "BIT_MATH.h"



void WDT_start(u8 time)
{
	SET_BIT(WDTCR,WDE);
	
	if(time == WDT_TIME_16_ms)
	{
		CLEAR_BIT(WDTCR,WDP0);
		CLEAR_BIT(WDTCR,WDP1);
		CLEAR_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_32_ms)
	{
		SET_BIT(WDTCR,WDP0);
		CLEAR_BIT(WDTCR,WDP1);
		CLEAR_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_65_ms)
	{
		CLEAR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLEAR_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_130_ms)
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLEAR_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_260_ms)
	{
		CLEAR_BIT(WDTCR,WDP0);
		CLEAR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_520_ms)
	{
		SET_BIT(WDTCR,WDP0);
		CLEAR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_1_s)
	{
		CLEAR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if(time == WDT_TIME_2_s)
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
}

void WDT_stop()
{
	WDTCR = (1<<WDTOE) | (1<<WDE);
	CLEAR_BIT(WDTCR,WDE); 
}
