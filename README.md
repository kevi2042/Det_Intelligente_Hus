# Det Intelligente Hus

## Lavt Med
Programmet er lavet i C sproget på Atmel studio. Programmet er skrevet til Arduino Boardet: Atmega2560.

## Forudsætninger
For at kunne køre dette program er det nødvendigt at havde disse ting til rådighed: 
- en Arduino Board 2560 (Eller en der kan de samme ting)
- en Matrix Keypad
- en LCD Display
- en RGB LED
- en Servo
- en LED Lys
- en Potentiometer

## Opbygning
[DIH - Opbygning 1.PNG](https://github.com/kevi2042/Det_Intelligente_Hus/blob/master/DIH%20-%20Opbygning%201.PNG "DIH - Opbygning 1.PNG")

[DIH - Opbygning 2.PNG](https://github.com/kevi2042/Det_Intelligente_Hus/blob/master/DIH%20-%20Opbygning%202.PNG "DIH - Opbygning 2.PNG")

| Porte 							| Bruges til  	|
|:---------------------------------:|:-------------:|
| PB6, PB5, PB4, PH6, PH5, PH4, PH3	| LCD Displayet |
| PF0, PF1, PF2				 		| RGB LED 		|
| PE3								| Servo 		|
| PA1 								| LED Lys 		|
| PK0 - PK7 						| Matrix Keypad |


## Problemformulering
Den overordned idé med opgaven er at jeg forstillede mig at lave en elektronisk dørlås hvor ejeren skulle indtaste sin pin kode for at låse døren op. Derefter har ejeren en controller til at styre alt elektronik inde i lejligheden, som lys eller garage dør osv. Dette førte til den nedenstående Problemformulering.

1. Låse døren op via pin kode system. (brug matrix keypad, LED display, lys og måske buzzer) LED displayet fremviser velkommst og beder efter input af brugeren, der bliver fremvist pin koden i kryptisk form. et lys lyser i forskellige farver alt efter om pin koden lykkedes eller ej. Hvis koden indtastes forkert 3 gange kører buzzeren?

2. Efter at låse døren op. Bruges keypad til at tænde slukke for lys

3. Brug keypad til at åbne/lukke garagedør(dreje stepmotor/eller servo)­­­

4. Brug Keypad til at låse døren igen.


## FlowChart
Flowchartet blev lavet som udgangspunk for programmet og beskriver overordnet hvordan programmet skal køre.

[Det_Intelligente_Hus.png](https://github.com/kevi2042/Det_Intelligente_Hus/blob/master/Det_Intelligente_Hus.png "Det_Intelligente_Hus.png")

## Architektur
Der er lavet 6 c. filer bortset fra main filen.
| Fil Navn 		| Beskrivelse |
|---------------|:------------|
| DoorLock	  | Indeholder alle funktioner til Dørlåsen						|
| Inits   	  | Indeholder alle defines og funktioner der skal initialiseres	|
| Keypad 	  | Indeholder funktioner til Matrix Keypad	|
| LCD_Display | Indeholder alle funktioner der udskriver til LCD Displayet	|
| MyHouse 	  | Indeholder menuen og funktioner der aktiverer ting inde i huset	|
| RGB_LED 	  | Indeholder funktioner der toggler farverne på RGB LED'en	|


## Defines

#### Delay
| Define 		| Indhold | Beskrivelse |
|---------------|:--------:|:---------:|
| CPUFREQUENZ	|16000000UL| Bruges til at definere F_CPU til delayet på forskellige sider|

#### Pin
| Define 		| Indhold 	| Beskrivelse |
|---------------|:---------:|:---------:|
| PINLENGTH 	| 4 		| Bruges til størrelsen af pinkoden til låsen |

#### Keypad
|Defines  				| Indholder  |
|-----------------------|-----------|
| MATRIX_PORT  			| PORTK 	|
| MATRIX_DDR 			| DDRK		|
| MATRIX_DDR_INPUTPORT 	| `(1<<PK0) | (1 << PK1) | (1<<PK2) | (1<<PK3)` |
| MATRIX_DDR_OUTPUTPORT | `(1<<PK4) | (1<<PK5) | (1<<PK6) | (1<<PK7)`	|
| MATRIX_PORT_OUTPUT0 	| (1<<PK4)	|
| MATRIX_PORT_OUTPUT1 	| (1<<PK5) 	|
| MATRIX_PORT_OUTPUT2 	| (1<<PK6)	|
| MATRIX_PORT_OUTPUT3 	| (1<<PK7)	|
| MATRIX_PORT_INPUT  	| PINK 	|
| MATRIX_PORT_INPUT0 	| PINK0	|
| MATRIX_PORT_INPUT1 	| PINK1 |
| MATRIX_PORT_INPUT2 	| PINK2	|
| MATRIX_PORT_INPUT3 	| PINK3	|

#### RGB LED

|Defines  				| Indholder  |
|-----------------------|-----------|
| RGB_PORT 				| PORTF  	|
| RGB_DDR 				|  DDRF		|
| RGB_DDR_INPUTPORT  	| `(1<<PF0) | (1 << PF1) | (1<< PF2)` |
| RGB_Red  				| (1<<PF0)	|
| RGB_Blue 				| (1<<PF2)	|
| RGB_Green 			| (1<<PF1) 	|
| RGB_Yellow 			| RGB_Red or RGB_Green 	|
| RGB_TOGGLE_RED 		| RGB_PORT = RGB_Red 	|
| RGB_TOGGLE_BLUE  		| RGB_PORT = RGB_Blue 	|
| RGB_TOGGLE_YELLow  	| RGB_PORT = RGB_Yellow |
| RGB_TOGGLE_GREEN  	| RGB_PORT = RGB_Green 	|

#### LED Lys
|Defines  				| Indholder  |
|-----------------------|-----------|
| LIGHT_DDR  			| DDRA 		|
| LIGHT_PORT  			|  PORTA 	|
| LIGHT_PORT_OUTPUT  	| (1<<PA1) 	|
| LIGHT_TOGGLE  		| LIGHT_PORT ^= LIGHT_PORT_OUTPUT |

#### Servo Port
|Defines  				| Indholder  |
|-----------------------|-----------|
| SERVO_DDR  			| DDRE 		|
| SERVO_PORT  			| (1<<PE3) 	|

#### Servo Timer
|Defines  					| Indholder  |
|---------------------------|-----------|
| SERVO_TIMER3A  			| TCCR3A 	|
| SERVO_TIMER3B  			| TCCR3B 	|
| SERVO_TIMER3_COM  		| `(1<<COM3A1) | (1 << COM3B1) | (1 << COM3C1)`|
| SERVO_TIMER3A_WGM  		| (1 << WGM31) 	|
| SERVO_TIMER3B_WGM   		| (1<<WGM33) 	|
| SERVO_TIMER3ICR  			| ICR3 = 20000 	|
| SERVO_TIMER3_PRESCALER  	| (1<<CS11) 	|
| SERVO_OC  				| OCR3A 	|

## Funktioner
#### DoorLock
| Navn 				| Beskrivelse 							|
|-------------------|---------------------------------------|
| void Doorlock() 	| tjekker på status af låsen og starter nødvendige funktioner |
| int PinCheck()	| kigger om pin stemmer over ens med brugerinput |
| void OpenLock() 	| Ber om indtastning af pin og tjekker om døren bliver låst op |
| void AddCharacter(char charakter) | tilføjer indgivet karakter til en global variabel |
| int TestInput() 	| tester om den indtastede pin har den korrekte længde |
| void ResetInput() | sætter den globale variabel til input tilbage til default |
| void InputError() | kører de nødvendige funktioner i tilfælde af forkert input |
| void LockOpened() | Starter menuen der skal bruges når låsen er åbnet |
| void LockOut() 	| Låser brugeren ude da der har været for mange forkerte inputs |
| void LockDoor() 	| Låser døren |
| int CheckLock() 	| tester om døren er låst eller ej |



#### Inits
| Navn 					| Beskrivelse 							|
|-----------------------|---------------------------------------|
| void Port_Init() 		| Kører alle initialiser funktioner nødvendige for programmet |
| void Init_Keypad() 	| Sætter Portne for keypad |
| void Init_RGBLED() 	| Sætter Portne for RGB LED (Kører via Pull up) |
| void Init_Timer3Servo() | Sætter Timer indstillinger for Timer3 der bruges til Servo |
| void Init_Servo() 	| Sætter Portne for Servo |
| void Display_Init() 	| Initialiser LCD Displayet |
| void Init_LIGTH() 	| Sætter Port for LED lyset |

#### Keypad
| Navn 					| Beskrivelse 							|
|-----------------------|---------------------------------------|
| int ColumnScan(int column) | Sætter columns skiftevis til logisk 0 |
| int ReadRows() 		| Tester rows efter input |
| char MatrixScanning() | Scanner keypaddet og sender karakteret tilbage |
| char DecodeKeyboard(int column, int row) | finder karakteret der passer til column og row |


#### LCD_Display
| Navn 								| Beskrivelse 							|
|-----------------------------------|---------------------------------------|
| void DisplayInput(char input[]) 	| Udskriver brugerens pin input som * for at brugeren kan se hvor mange tal han har indtastet|
| void DisplayPinCheck() 			| Udskriver til displayet når låset checkes |
| void DisplayDoorLocked() 			| Udskriver til displayet hvis døren er låst |
| void DisplayLockOpen() 			| Udskriver til displayet hvis døren er låst op |
| void DisplayError(int pincount) 	| Udskriver at brugeren har indtastet forkert og viser om brugeren har en chance til endnu |
| void DisplayLockout() 			| Udskriver til displayet at brugeren ikke har flere forsøg og at han er låst ude |
| void DisplayMyHomeGreeting() 		| Udskriver til displayet at brugen er kommet inde i huset |
| void DisplayChoices() 			| Udskriver de valgmuligheder brugeren har inde i huset |

#### MyHouse
| Navn 								| Beskrivelse 							|
|-----------------------------------|---------------------------------------|
| void HouseMenu() 					| Viser valgmuligheder brugeren har og tager imode brugerens input |
| void HouseController(char choice) | Kører den valgte funktion alt efter hvad brugeren har indtastet |
| void ToggleGarage()				| Drejer Servo til modsatte side |
| void ToggleLight() 				| Toggler lyset |

#### RGB_LED
| Navn 					| Beskrivelse 							|
|-----------------------|---------------------------------------|
| void Toggle_Red() 	| Tænder for Rødt lys |
| void Toggle_Blue() 	| Tænder for Blåt lys |
| void Toggle_Yellow() 	| Tænder for Gult lys |
| void Toggle_Green() 	| Tænder for Grønt lys |

## Globale Variabler
| Variabel 					| Beskrivelse |
|---------------------------|------------|
| static char matrix[4][4] 	| indeholder karaktere som findes på keypad |
| char input[6] = "****" 	| Brugerens input som sammenlignes med pin koden til låset, default den sat til stjerner for at man kan genbruge samme variabel |
| int wrongPinCount 		| antal af forsøg brugeren har brugt |
| int lock 					| en bool værdi der fortæller om døren er låst eller låst op |

## Skaber
Kevin Wolff - [https://github.com/kevi2042/Det_Intelligente_Hus](https://github.com/kevi2042/Det_Intelligente_Hus)


