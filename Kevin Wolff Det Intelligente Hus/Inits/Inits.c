/*
 * Inits.c
 *
 * Created: 13-12-2019 12:25:03
 *  Author: kevi2042
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../LCD/lcd.h"
#include "Inits.h"

#define F_CPU CPUFREQUENZ
#include <util/delay.h>

//initialiser portne
void Port_Init(){
	Init_Keypad();
	Display_Init();
	Init_RGBLED();
	Init_Timer3Servo();
	Init_Servo();
	Init_LIGTH();
}

//Sætter port for Keypad
void Init_Keypad(){
		//sætter input port (Pull up) på matrix keypad
		MATRIX_DDR &= ~MATRIX_DDR_INPUTPORT;
		
		// PK0-3 er High, PK4-7 er Low
		MATRIX_DDR |= MATRIX_DDR_OUTPUTPORT;
		
		//Sætter alle Port til 1
		MATRIX_PORT |= 0xFF;
		////		PK4	PK5	PK6	PK7
		////	PK0	 0	 0	 0	 0
		////	PK1	 0	 0	 0	 0
		////	PK2	 0	 0	 0	 0
		////	PK3	 0	 0	 0	 0
}

//Sætter port for RGB LED
void Init_RGBLED(){
	//sætter input port (pull up) på RGB LED
	RGB_DDR &= ~RGB_DDR_INPUTPORT;
}

//Sætter port for almindelig lys
void Init_LIGTH(){
	LIGHT_DDR |= LIGHT_PORT_OUTPUT;
}

// Sætter Port for Servo
void Init_Servo(){
	SERVO_DDR |= SERVO_PORT;
}

//Sætter Timer indstillinger der bruges til Servo
void Init_Timer3Servo(){
		// Compare Output Mode: Fast PWM Mode:  (Table 16-3)
		SERVO_TIMER3A |= SERVO_TIMER3_COM;					// datasheet 17.11.3
		
		//Waveform Generation Mode: Mode 10 Phase Correct PWM: WGM31 = 1, WGM33 = 1 (Table 17.9.1)
		SERVO_TIMER3A |= SERVO_TIMER3A_WGM;
		SERVO_TIMER3B |= SERVO_TIMER3B_WGM;
		
		// Clock Select Bit: clk/256 prescaling: CS11 = 1 (Table 17-6)
		SERVO_TIMER3B |= SERVO_TIMER3_PRESCALER;		// datasheet 17.11.8
		SERVO_TIMER3ICR;
		
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