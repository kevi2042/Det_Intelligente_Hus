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

char input[6] = "****";
int wrongPinCount = 0;
int lock = 0;

// Kigger om d�re er l�st eller ej, og v�lger hvilken menu programmet skal k�re
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

// Funktion der ber om pin og �bner l�sen alt efter om pin er rigtig eller ej
void OpenLock(){
	char hiddenPin[] = "1234";
	
	
	// display locked
	DisplayDoorLocked();
	
	//K�rer while s� l�nge at input og hiddenpin ikke er ens
	while (PinCheck(input, hiddenPin) == 0)
	{
		// RGB LED Lyser bl�
		Toggle_Blue();
		
		//if til hvis brugeren har indtastet den forkerte pin 3 gange
		if(wrongPinCount == 3){
			lock = -1;
			break;
		}
		else{
			//While til scanning af matrix. k�rer indtil alt p� inputtet indeholder andet end *
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
	//Hvis pin stemmer over ens
	if(PinCheck(input, hiddenPin) == 1){
		wrongPinCount = 0;
		lock = 1;
		DisplayLockOpen();
		Toggle_Green();
		DisplayMyHomeGreeting();
	}
	//programmet kommer kun ud af while lykken hvis d�ren er l�st op. (Lockcheck returnerer kun 0 eller 1)
}

// K�rer n�dvendige funktioner til hvis brugeren indtaster forkert
void InputError(){
		//RGB LED lyser r�d
		Toggle_Red();
		wrongPinCount++;
		DisplayError(wrongPinCount);
		ResetInput();
}

// kigger om input og hiddenPin stemmer over ens
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

// tilf�jer charakter til global variablen: input
void AddCharacter(char charakter){
	//for at bruge string metoder kr�ver det at stringet indeholder "\0" i slutningen
	for (int i = 0; i < PINLENGTH;i++)
	{
		if(input[i] == '*'){
			input[i] = charakter;
			break;
		}
	}
}

// tester input om alle karakterer er blevet �ndret fra * til noget andet
int TestInput(){
	if(input[PINLENGTH-1] == '*'){
		return 0;
	}
	else{
		return 1;
	}
}

// s�tter Global variabel input, til default: ****
void ResetInput(){
	for (int i = 0; i < PINLENGTH;i++)
	{
		input[i] = '*';
	}
}

// K�rer funktioner hvis l�sen er l�st op
void LockOpened(){
	Toggle_Green();
	HouseMenu();
}

// lukker brugeren ude hvis pin er inputtet 3 gange forkert
void LockOut(){
	DisplayLockout();
	Toggle_Red();
	while(1){
		//Det er ikke meningen at brugeren kan komme ud af denne while lykke
	}
}

// l�ser d�ren og nulstiller input
void LockDoor(){
	lock = 0;
	ResetInput();
}

// kigger om d�ren er l�st
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