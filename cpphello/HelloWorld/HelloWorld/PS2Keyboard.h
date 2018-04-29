#pragma once
#include<iostream>
#include<conio.h>

#define PS2_ENTER 13

/*
	Dummy PS2Keyboard Class for Testing without Hardware Integration.
	Read Data from the Standard Input
*/
class PS2Keyboard {
public:
	void begin(int data_pin) {
		// do nothing
	}
	bool available() {
		return true;
	}
	char read() {
		return _getch();
	}
};
