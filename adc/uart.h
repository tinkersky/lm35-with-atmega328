/*
 * uart.h
 *
 * Created: 28-03-2020 09:20:51
 *  Author: Chaitali
 */ 


#ifndef UART_H_
#define UART_H_

void UART_Init();
char UART_RxChar();
void UART_TxChar(char data);
void UART_TxString(char text[]);

#endif /* UART_H_ */