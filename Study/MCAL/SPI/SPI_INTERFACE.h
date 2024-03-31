

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"


#define SPCR (*(volatile u8*)0x2D)
#define SPE 6
#define MSTR 4
#define SPR0 0
#define SPR1 1

#define SPSR (*(volatile u8*)0x2E)
#define SPIF 7

#define SPDR (*(volatile u8*)0x2F)

#define SPI_MASTER 0
#define SPI_SLAVE 1
#define SPI_MODE SPI_MASTER

void SPI_init();

void SPI_write(u8 data);

u8 SPI_read();


#endif /* SPI_INTERFACE_H_ */