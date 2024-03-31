


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "STD_TYPES.h"

void EEPROM_init();

void EEPROM_writeData(u8 data,u16 location);

u8 EEPROM_readData(u16 location);


#endif /* EEPROM_INTERFACE_H_ */