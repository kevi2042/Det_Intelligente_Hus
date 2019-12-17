/*
 * LED_Display.c
 *
 * Created: 17-12-2019 09:24:11
 *  Author: kevi2042
 */ 


// viser input
void DisplayInput(char input[]){
	//for at udskrive en string skal der være \0 i slutningen
	char output[6];
	char krypt = "*";
	for (int i = 0; i < strlen(input); i++)
	{
		strcat(output,krypt);
	}
	lcd_puts(output);
// 	switch(strlen(input)){
// 		case 1:
// 			lcd_puts("*");
// 			break;
// 		case 2:
// 			lcd_puts("**");
// 			break;
// 		case 3:
// 			lcd_puts("***");
// 			break;
// 		case 4:
// 			lcd_puts("****");
// 			break;
// 		default:
// 			break;
// 	}
}

void DisplayClear(){
	lcd_clrscr();
}

void DisplayLockCheck(){
	lcd_puts("Checking Lock");
}

void DisplayDoorLocked(){
	lcd_puts("Locked");
}

void DisplayInputPin(){
	lcd_puts("Input pin");
	lcd_gotoxy(0,1);
}

void DisplayLockOpen(){
	lcd_puts("Unlocked");
}