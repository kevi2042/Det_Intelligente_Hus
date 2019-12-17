/*
 * Inits.h
 *
 * Created: 13-12-2019 12:24:54
 *  Author: kevi2042
 */ 

#include "avr/io.h"

#ifndef INITS_H_
#define INITS_H_

//-----------------------------------------global defines---------------------------------------
//------Keypad------
#pragma region Matrix_Keypad
//Port og output/input
#define MATRIX_PORT PORTK
#define MATRIX_DDR DDRK
#define MATRIX_DDR_INPUTPORT (1<<PK0) | (1 << PK1) | (1<<PK2) | (1<<PK3)	//input porte - Pull up
#define MATRIX_DDR_OUTPUTPORT (1<<PK4) | (1<<PK5) | (1<<PK6) | (1<<PK7)	//output porte

//defines Til Ports
//output Porte til Column
#define MATRIX_PORT_OUTPUT0 (1<<PK4)
#define MATRIX_PORT_OUTPUT1 (1<<PK5)
#define MATRIX_PORT_OUTPUT2 (1<<PK6)
#define MATRIX_PORT_OUTPUT3 (1<<PK7)

//input Porte til Row
#define MATRIX_PORT_INPUT PINK
#define MATRIX_PORT_INPUT0 PINK0
#define MATRIX_PORT_INPUT1 PINK1
#define MATRIX_PORT_INPUT2 PINK2
#define MATRIX_PORT_INPUT3 PINK3
#pragma endregion Matrix_Keypad
//------------------

//------RGB LED-----
#pragma region RGB_LED
//Port
#define RGB_PORT PORTF
#define RGB_DDR DDRF
#define RGB_DDR_INPUTPORT (1<<PF0) | (1 << PF1) | (1<< PF2)

//enkelte port til farverne
#define RGB_Red (1<<PF0)
#define RGB_Blue (1<<PF2)
#define RGB_Green (1<<PF1)
#define RGB_Yellow RGB_Red | RGB_Green

//toggles for at få lysne til at lyse
#define RGB_toggle_RED RGB_PORT = RGB_Red
#define RGB_toggle_BLUE RGB_PORT = RGB_Blue
#define RGB_toggle_YELLow RGB_PORT = RGB_Yellow
#define RGB_toggle_GREEN RGB_PORT = RGB_Green

#pragma endregion RGB_LED
//-------------


//-----------------------------------------------------------------------------------------------

void Port_Init();
void Init_Keypad();
void Init_RGBLED();

void Display_Init();
void Display_Setup(int column, int row);


#endif /* INITS_H_ */