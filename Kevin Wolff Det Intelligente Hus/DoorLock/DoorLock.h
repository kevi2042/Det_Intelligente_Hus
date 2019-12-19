/*
 * DoorLock.h
 *
 * Created: 16-12-2019 14:25:52
 *  Author: kevi2042
 */ 


#ifndef DOORLOCK_H_
#define DOORLOCK_H_
#define PINLENGTH 4

void Doorlock();
int PinCheck();
void OpenLock();
void AddCharacter(char charakter);
int TestInput();
void ResetInput();
void InputError();
void LockOpened();
void LockOut();
void LockDoor();
int CheckLock();

#endif /* DOORLOCK_H_ */