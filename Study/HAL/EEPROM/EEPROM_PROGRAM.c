

#include "EEPROM_INTERFACE.h"
#include "BIT_MATH.h"
#include "I2C_INTERFACE.h"

void EEPROM_init()
{
	I2C_init(MASTER);
}

void EEPROM_writeData(u8 data,u16 location)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//address_3bitLocation_w
	TWDR = 0b10100000 | (GET_BIT(location,10)<<3) | (GET_BIT(location,9)<<2) | (GET_BIT(location,8)<<1);
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//8bitLocation
	TWDR = (u8)location;   //(u8) for casting
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send data
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

u8 EEPROM_readData(u16 location)
{
	/////dummy write/////
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//address_3bitLocation_w
	TWDR = 0b10100000 | (GET_BIT(location,10)<<3) | (GET_BIT(location,9)<<2) | (GET_BIT(location,8)<<1);
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//8bitLocation
	TWDR = (u8)location;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//address_3bitLocation_r
	TWDR = 0b10100001 | (GET_BIT(location,10)<<3) | (GET_BIT(location,9)<<2) | (GET_BIT(location,8)<<1);
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//read data -> NACK
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	u8 data = TWDR;
	
	//send stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	return data;
}
