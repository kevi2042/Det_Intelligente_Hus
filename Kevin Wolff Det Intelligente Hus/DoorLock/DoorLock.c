/*
 * DoorLock.c
 *
 * Created: 16-12-2019 14:26:02
 *  Author: kevi2042
 */ 
#define F_CPU CPUFREQUENZ

#include "../Inits/Inits.h"
#include "../Keypad/Keypad.h"
#include "../LCD_Display/LCD_Display.h"
#include "../MyHouse/House.h"
#include "DoorLock.h"
#include <string.h>
#include <util/delay.h>

static char input[6] = "****";
static int wrongPinCount = 0;
static int lock = 0;

void Doorlock(){
	if(lock == 0){
		OpenLock();
	}
	else if(lock == 1){
		LockOpened();
	}
	else{
		LockOut();
	}
}

void OpenLock(){
	char hiddenPin[] = "1234";
	
	
	// display locked
	DisplayDoorLocked();
	
	//Kører while så længe at input og hiddenpin ikke er ens
	while (PinCheck(input, hiddenPin) == 0)
	{
		// RGB LED Lyser blå
		Toggle_Blue();
		
		//if til hvis brugeren har indtastet den forkerte pin 3 gange
		if(wrongPinCount == 3){
			lock = -1;
		}
		else{
			//While til scanning af matrix. kører indtil alt på inputtet indeholder andet end *
			while (TestInput() == 0)
			{
				DisplayInput(input);
				char result = MatrixScanning();
				AddCharacter(result);
				_delay_ms(200);
			}
			//If til check om input er forkert
			if(PinCheck(input, hiddenPin) == 0){
				InputError();
			}
		}
	}
	wrongPinCount = 0;
	lock = 1;
	DisplayLockOpen();
	Toggle_Green();
	DisplayMyHomeGreeting();
	//programmet kommer kun ud af while lykken hvis døren er låst op. (Lockcheck returnerer kun 0 eller 1)
}

void InputError(){
		//RGB LED lyser rød
		Toggle_Red();
		wrongPinCount++;
		DisplayError(wrongPinCount);
		ResetInput();
}

int PinCheck(char input[], char hiddenPin[]){
	// ved strcmp returnere den 0 hvis begge strings er ens.
	int cmpvalue = strcmp(input, hiddenPin);
	if(cmpvalue == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void AddCharacter(char charakter){
	//for at bruge string metoder kræver det at stringet indeholder "\0" i slutningen
	for (int i = 0; i < PINLENGTH;i++)
	{
		if(input[i] == '*'){
			input[i] = charakter;
			break;
		}
	}
}

int TestInput(){
	if(input[PINLENGTH-1] == '*'){
		return 0;
	}
	else{
		return 1;
	}
}

void ResetInput(){
	for (int i = 0; i < PINLENGTH;i++)
	{
		input[i] = '*';
	}
}

void LockOpened(){
	Toggle_Green();
	HouseMenu();
}

void LockOut(){
	DisplayLockout();
	Toggle_Red();
	while(1){
		//Det er ikke meningen at brugeren kan komme ud af denne while lykke
	}
}

void LockDoor(){
	lock = 0;
	ResetInput();
}

int CheckLock(){
	if(lock == 0){
		return 0;
	}
	else if(lock == 1){
		return 1;
	}
	else{
		return -1;
	}
}