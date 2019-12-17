/*
 * Keypad.h
 *
 * Created: 13-12-2019 12:14:01
 *  Author: kevi2042
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

static char matrix[4][4] = {{'1','4','7','*'}, {'2','5','8','0'}, {'3','6','9','#'}, {'A','B','C','D'}};


char MatrixScanning();
int ColumnScan(int column);
int ReadRows();
char DecodeKeyboard(int column, int row);



#endif /* KEYPAD_H_ */