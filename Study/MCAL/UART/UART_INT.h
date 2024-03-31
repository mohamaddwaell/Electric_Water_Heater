/*
 * UART_INT.h
 *
 * Created: 24/02/2024 08:16:06 PM
 *  Author: AMIT
 */ 


#ifndef UART_INT_H_
#define UART_INT_H_


#define UART_NOT_RECEIVED	'x'

void UART_init();

void UART_sendData(u8 data);

void UART_sendString(u8* str);

u8 UART_receiveData();




#endif /* UART_INT_H_ */