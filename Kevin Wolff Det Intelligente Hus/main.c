/*
 * Kevin Wolff Det Intelligente Hus.c
 *
 * Created: 16-12-2019 12:22:10
 * Author : kevi2042
 */ 

#include <avr/io.h>
#include <string.h>
#include "DoorLock/DoorLock.h"
#include "Inits/Inits.h"

#define F_CPU CPUFREQUENZ
#include <util/delay.h>



int main(void)
{
	char buffer[7];


	Port_Init();
    /* Replace with your application code */
    while (1) 
    {
		
		Doorlock();
    }
}

