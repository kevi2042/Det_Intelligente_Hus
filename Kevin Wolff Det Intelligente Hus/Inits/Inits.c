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