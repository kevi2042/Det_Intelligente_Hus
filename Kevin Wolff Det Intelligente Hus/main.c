/*
 * Kevin Wolff Det Intelligente Hus.c
 *
 * Created: 16-12-2019 12:22:10
 * Author : kevi2042
 */ 
#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "Inits/Inits.h"
#include "DoorLock/DoorLock.h"



int main(void)
{
	char buffer[7];


	
	Port_Init();
    /* Replace with your application code */
    while (1) 
    {
		Display_Init();
		
		Doorlock();
    }
}

