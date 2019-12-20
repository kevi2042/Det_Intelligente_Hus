/*
 * House.c
 *
 * Created: 18-12-2019 10:42:39
 *  Author: kevi2042
 */ 

#include <avr/interrupt.h>
#include "../LCD_Display/LCD_Display.h"
#include "../DoorLock/DoorLock.h"
#include "../Keypad/Keypad.h"
#include "../Inits/Inits.h"
#include "House.h"

#define F_CPU CPUFREQUENZ
#include <util/delay.h>

// viser husets menu og venter på input af brugeren.
void HouseMenu(){
	DisplayChoices();
	while(CheckLock() == 1){
		char choice = MatrixScanning();
		HouseController(choice);
		_delay_ms(200);
	}
}

// kører valget af brugeren
void HouseController(char choice){
	switch(choice){
		case 'A':
		ToggleLight();
		break;
		case 'B':
		ToggleGarage();
		break;
		case 'C':
		LockDoor();
		break;
		default:
		break;
	}
}

// Tænder/Slukker lys
void ToggleLight(){
	LIGHT_TOGGLE;
}

// Åbner/Lukker Garage(Servo)
void ToggleGarage(){
	static int switcher = 0;
	if(switcher == 0){
		for (int i = 500; i < 2600; i++)
		{
			SERVO_OC = i;
			_delay_ms(1);
		}
	}
	else if(switcher == 1){
		for (int i = 2600; i > 500; i--)
		{
			SERVO_OC = i;
			_delay_ms(1);
		}
	}
	
	switcher++;
	if(switcher > 1){
		switcher = 0;
	}
}