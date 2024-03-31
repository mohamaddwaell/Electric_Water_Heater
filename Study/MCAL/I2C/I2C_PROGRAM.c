

#include "I2C_INTERFACE.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void I2C_init(enum I2C_mode mode)
{
	if(mode == MASTER)
	{
		
	}
	else if(mode == SLAVE)
	{
		TWAR = I2C_SLAVE_ADDRESS << 1;
	}
	SET_BIT(TWCR,TWEN);
	TWBR = 72;
}

void I2C_sendData(u8 data,u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	CLEAR_BIT(x, 0);     //write
	TWDR = x;          //address_w
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );   //wait for the address
	
	//send data
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

u8 I2C_receiveDataAck(u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	SET_BIT(x, 0);     //read
	TWDR = x;          //address_r
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );   //wait for the address
	
	//read data ->acknowledge
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);  //wait for the data
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	return TWDR;
}


u8 I2C_receiveDataNoAck(u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	SET_BIT(x, 0);     //read
	TWDR = x;          //address_r
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );   //wait for the address
	
	//read data ->NO_acknowledge
	TWCR = (1<<TWINT) | (1<<TWEN);  //wait for the data
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	return TWDR;
}