/*
 * GasSensorTest.c
 *
 * Created: 09-04-2020 09:30:59
 * Author : Bruger
 */ 
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "UART/uart.h"
#include "MQDriver/MQ_135.h"

int main(void)
{
	Init_MQ();
	MqCalibrate(CO2);
	
	while(1)
	{
		SendString("CO2 :");
		float ppm = MQGetGasPercentage(CO2);
		SendInteger(ppm);
		SendString("\r \n");
		_delay_ms(1000);
	}
}



