

#include "SPI_INTERFACE.h"
#include "DIO_INTERFACE.h"
#include "BIT_MATH.h"



void SPI_init()
{
	#if(SPI_MODE == SPI_MASTER)
	{
		SET_BIT(SPCR,MSTR);
		DIO_setPinDir(DIO_PINB4,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB5,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB6,DIO_INPUT);
		DIO_setPinDir(DIO_PINB7,DIO_OUTPUT);
	}
	#elif(SPI_MODE == SPI_SLAVE)
	{
		CLEAR_BIT(SPCR,MSTR);
		DIO_setPinDir(DIO_PINB4,DIO_INPUT);
		DIO_setPinDir(DIO_PINB5,DIO_INPUT);
		DIO_setPinDir(DIO_PINB6,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB7,DIO_INPUT);
	}
	#endif
	SET_BIT(SPCR,SPE);
}

void SPI_write(u8 data)
{
	//refresh slave select
	DIO_setPinValue(DIO_PINB4,DIO_HIGH);
	DIO_setPinValue(DIO_PINB4,DIO_LOW);
	SPDR = data;
	while(GET_BIT(SPSR,SPIF) == 0);
}

u8 SPI_read()
{
	while(GET_BIT(SPSR,SPIF) == 0);
	return SPDR;
	
}