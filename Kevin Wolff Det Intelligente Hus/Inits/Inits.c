/*
 * Inits.c
 *
 * Created: 13-12-2019 12:25:03
 *  Author: kevi2042
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "../LCD/lcd.h"
#include "Inits.h"

//defines


//initialiser portne
void Port_Init(){
	Init_Keypad();
	Display_Init();
	Init_RGBLED();
	Init_Timer3Servo();
	Init_Servo();
	Init_LIGTH();
}

void Init_Keypad(){
		//sætter input port (Pull up) på matrix keypad
		MATRIX_DDR &= ~MATRIX_DDR_INPUTPORT;
		
		// PK0-3 er High, PK4-7 er Low
		MATRIX_DDR |= MATRIX_DDR_OUTPUTPORT;
		MATRIX_PORT |= 0xFF;
		////		PK4	PK5	PK6	PK7
		////	PK0	 0	 0	 0	 0
		////	PK1	 0	 0	 0	 0
		////	PK2	 0	 0	 0	 0
		////	PK3	 0	 0	 0	 0
}

void Init_RGBLED(){
	//sætter input port (pull up) på RGB LED
	RGB_DDR &= ~RGB_DDR_INPUTPORT;
}

void Init_LIGTH(){
	
}

void Init_Servo(){
	SERVO_DDR |= SERVO_PORT;
}

void Init_Timer3Servo(){
		// Compare Output Mode: Fast PWM Mode: Clear OC0A on Compare Match, set OC0A at BOTTOM, non-inverting mode (Table 16-3)
		SERVO_TIMER3A |= SERVO_TIMER3_COM;					// datasheet 16.9.1
		
		//Waveform Generation Mode: Mode 5 Phase Correct PWM: WGM0 = 1, WGM2 = 1 (Table 16-8)
		SERVO_TIMER3A |= SERVO_TIMER3A_WGM;
		SERVO_TIMER3B |= SERVO_TIMER3B_WGM;
		
		// Clock Select Bit: clk/64 prescaling: CS = 011 : CS01 = 1, CS00 = 1 (Table 16-9), frekv. = 980Hz
		SERVO_TIMER3B |= SERVO_TIMER3_PRESCALER;		// datasheet 16.9.2
		ICR3 = 20000;
}

//initialiserer display
void Display_Init(){
	/* initialize display, cursor on */
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);

	/* clear display and home cursor */
	lcd_clrscr();
}

//starter display op med column og row info
void Display_Setup(int column, int row){
	char buffer[7];
	
	lcd_puts("Column ");
	itoa(column, buffer, 10);
	lcd_puts(buffer);
	lcd_puts(" Row ");
	itoa(row, buffer, 10);
	lcd_puts(buffer);
	lcd_puts("\r\n");
}