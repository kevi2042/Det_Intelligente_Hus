/*
 * LCD_Display.c
 *
 * Created: 17-12-2019 09:24:11
 *  Author: kevi2042
 */ 

#include "../Inits/Inits.h"
#include "LCD_Display.h"

#define F_CPU CPUFREQUENZ
#include <util/delay.h>

// viser input
void DisplayInput(char input[]){
	lcd_clrscr();
	lcd_gotoxy(0,0);
	lcd_puts("Input pin");
	lcd_gotoxy(0,1);
	
	
	//for at udskrive en string skal der være \0 i slutningen
	char output[6] = "";
	char krypt[] = "*\0";
	for (int i = 0; i < strlen(input); i++)
	{
		if(input[i] != '*'){
			strcat(output,krypt);
		}
	}
	lcd_puts(output);
}

// viser pin check
void DisplayPinCheck(){
	lcd_clrscr();
	lcd_puts("Checking Lock");
}

// viser døren er låst
void DisplayDoorLocked(){
	lcd_clrscr();
	DisplayPinCheck();
	_delay_ms(DISPLAYDELAY);
	lcd_gotoxy(0,1);
	lcd_puts("Locked");
	_delay_ms(DISPLAYDELAY);
}

// viser døren er låst op
void DisplayLockOpen(){
	DisplayPinCheck();
	_delay_ms(DISPLAYDELAY);
	lcd_gotoxy(0,1);
	lcd_puts("Unlocked");
	_delay_ms(DISPLAYDELAY);
}

// viser error og advarsel
void DisplayError(int pincount){
	lcd_clrscr();
	lcd_puts("Error: Wrong Pin");
	lcd_gotoxy(0,1);
	switch (pincount)
	{
		case 1:
			lcd_puts("Try again");
			break;
		case 2:
			lcd_puts("Last chance");
			break;
		default:
		break;
	}
	_delay_ms(DISPLAYDELAY);
}

// viser brugeren er lukket ude
void DisplayLockout(){
	lcd_clrscr();
	lcd_puts("Too Many Errors");
	lcd_gotoxy(0,1);
	lcd_puts("Locked out :D");
}

// viser brugeren er kommet ind i huset
void DisplayMyHomeGreeting(){
	lcd_clrscr();
	lcd_puts("Welcome to");
	lcd_gotoxy(0,1);
	lcd_puts("My Home");
	_delay_ms(DISPLAYDELAY);	
}

// viser husets menu
void DisplayChoices(){
		lcd_clrscr();
		lcd_puts("A:Light ");
		lcd_puts("B:Garage");
		lcd_gotoxy(0,1);
		lcd_puts("C:Lock Door");
}