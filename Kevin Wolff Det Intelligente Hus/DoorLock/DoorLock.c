/*
 * DoorLock.c
 *
 * Created: 16-12-2019 14:26:02
 *  Author: kevi2042
 */ 
#define F_CPU 16000000UL

#include "../Inits/Inits.h"
#include "../Keypad/Keypad.h"
#include "../LED_Display/LED_Display.h"
#include "DoorLock.h"
#include <string.h>
#include <util/delay.h>


static char input[6] = "";

void OpenLock(){
	char hiddenPin[] = "1234";
	static int wrongPinCount = 0;
	
	//Checking Lock
	DisplayClear();
	DisplayLockCheck();
	_delay_ms(2000);
	
	if(LockCheck(input, hiddenPin) == 1){
		// do nothing
		DisplayLockOpen();
		_delay_ms(2000);
	}
	else{
		lcd_gotoxy(0,1);
		//Display "Locked"
		DisplayClear();
		DisplayDoorLocked();
		_delay_ms(2000);
	
		while (1)
		{
			DisplayClear();
			lcd_gotoxy(0,0);
			DisplayInputPin();
			lcd_gotoxy(0,1);
			DisplayInput(input);
			char result = MatrixScanning();
			AddCharacter(result);
			_delay_ms(400);
		}
	}
	
}

int LockCheck(char input[], char hiddenPin[]){
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
	if(TestInputLength(input) == 0){
		char string[] = {charakter, "\0"};
		strcat(input, string);
	}
}

int TestInputLength(char input[]){
	if(strlen(input) == 4){
		return 1;
	}
	else{
		return 0;
	}
}