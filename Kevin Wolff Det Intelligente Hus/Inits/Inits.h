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
#define RGB_TOGGLE_RED RGB_PORT = RGB_Red
#define RGB_TOGGLE_BLUE RGB_PORT = RGB_Blue
#define RGB_TOGGLE_YELLow RGB_PORT = RGB_Yellow
#define RGB_TOGGLE_GREEN RGB_PORT = RGB_Green

#pragma endregion RGB_LED
//-------------

#pragma endregion Timer3

#pragma region LIGHT
#define LIGHT_DDR DDRA
#define LIGHT_PORT PORTA
#define LIGHT_PORT_OUTPUT (1<<PA1)
#define LIGHT_TOGGLE LIGHT_PORT ^= LIGHT_PORT_OUTPUT

#pragma endregion LIGHT



#pragma region Servo

#define SERVO_DDR DDRE
#define SERVO_PORT (1<<PE3)

#pragma endregion Servo

#pragma region Timer3

#define SERVO_TIMER3A TCCR3A
#define SERVO_TIMER3B TCCR3B

#define SERVO_TIMER3_COM (1<<COM3A1) | (1 << COM3B1) | (1 << COM3C1)
#define SERVO_TIMER3A_WGM (1 << WGM31)
#define SERVO_TIMER3B_WGM  (1<<WGM33)

#define SERVO_TIMER3_PRESCALER (1<<CS11)
#define SERVO_OC OCR3A



//-----------------------------------------------------------------------------------------------

void Port_Init();
void Init_Keypad();
void Init_RGBLED();
void Init_Timer3Servo();
void Init_Servo();
void Display_Init();
void Display_Setup(int column, int row);
void Init_LIGTH();

#endif /* INITS_H_ */