/*
 * LCD_Display.h
 *
 * Created: 17-12-2019 09:24:01
 *  Author: kevi2042
 */ 


#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_
#define DISPLAYDELAY 1500


void DisplayInput(char input[]);
void DisplayPinCheck();
void DisplayDoorLocked();
void DisplayLockOpen();
void DisplayError(int pincount);
void DisplayLockout();
void DisplayMyHomeGreeting();
void DisplayChoices();

#endif /* LCD_DISPLAY_H_ */