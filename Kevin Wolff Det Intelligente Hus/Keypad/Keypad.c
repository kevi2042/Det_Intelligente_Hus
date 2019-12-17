/*
 * Keypad.c
 *
 * Created: 13-12-2019 12:14:09
 *  Author: kevi2042
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "../LCD/lcd.h"
#include "Keypad.h"
#include "../Inits/Inits.h"


char MatrixScanning(){
	int column = 0;
	int row = -1;
	
	while(row == -1){
		ColumnScan(column);
		row = ReadRows();
		
		if(row == -1){
			column++;
			if(column > 3){
				column = 0;
			}
		}
	}
	return DecodeKeyboard(column, row);
}

//scanner columns efter hvilken der er blevet klikket på
int ColumnScan(int column){
	if(column == 0){
		MATRIX_PORT = ~MATRIX_PORT_OUTPUT0;
	}
	else if(column == 1){
		MATRIX_PORT = ~MATRIX_PORT_OUTPUT1;
	}
	else if(column == 2){
		MATRIX_PORT = ~MATRIX_PORT_OUTPUT2;
	}
	else if(column == 3){
		MATRIX_PORT = ~MATRIX_PORT_OUTPUT3;
	}
	
	return column;
}

// læser hvilken row der er klikket på
int ReadRows(){
 	if(~MATRIX_PORT_INPUT & (1<< MATRIX_PORT_INPUT0)){
		 _delay_ms(10);
		 if(~MATRIX_PORT_INPUT & (1<< MATRIX_PORT_INPUT0)){
		 	return 0;
		 }
		 else{
			 return -1;
		 }
	 }
 	else if(~MATRIX_PORT_INPUT & (1 << MATRIX_PORT_INPUT1)){
		_delay_ms(10);
		if(~MATRIX_PORT_INPUT & (1<< MATRIX_PORT_INPUT1)){
			return 1;
		}
		else{
			return -1;
		}
	}
	else if(~MATRIX_PORT_INPUT & (1 << MATRIX_PORT_INPUT2)){
		_delay_ms(10);
		if(~MATRIX_PORT_INPUT & (1<< MATRIX_PORT_INPUT2)){
			return 2;
		}
		else{
			return -1;
		}
	}
	else if(~MATRIX_PORT_INPUT & (1 << MATRIX_PORT_INPUT3)){
		_delay_ms(10);
		if(~MATRIX_PORT_INPUT & (1<< MATRIX_PORT_INPUT3)){
			return 3;
		}
		else
		{
			return -1;
		}
	}
	else{
		return -1;
	}
}

// finder den character som passer til row og column der er klikket på
char DecodeKeyboard(int column, int row){
	return matrix[column][row];
}



