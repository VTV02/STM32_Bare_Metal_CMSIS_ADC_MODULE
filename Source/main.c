#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#define GPIOAEN			(1U<<0)


char key;
uint32_t Sensor_value;
int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_txrx_init();
	pa1_adc_init();
	star_conversion();
	while(1)
	{
		if(key=='1')
		{
			Sensor_value=adc_read();
			write_string(2,Sensor_value);
		}
		if(key=='0')
		{
			write_string(4,'None');
		}


	}
}

