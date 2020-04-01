#define F_CPU 16000000

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "uart.h"

void ADC_Init(){
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint8_t ADC_Read(){ 
	ADCSRA |= 1<<ADSC;
	return ADC;
}

int main(void)
{
	UART_Init();
	ADC_Init();
	
	while (1)
	{
		uint8_t adc_value = ADC_Read()*0.4882;
		char val[4];
		itoa(adc_value,val,10);
		UART_TxString(val);
		UART_TxString("\r\n");
		_delay_ms(1000);
	}
}


