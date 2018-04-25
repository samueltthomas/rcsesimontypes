#pragma once

#include <iostream>
#include <string>
#include "Utils.h"

/* 
	Dummy LiquidCrystal Class for Testing without Hardware Integration.
	Print Text on the Standard Display instead of LCD
*/

class LiquidCrystal {
public:

	LiquidCrystal(int rs, int en, int d4, int d5, int d6, int d7) {
		// do nothing
	}

	void begin(int n1,int n2) {
		// do nothing
	}

	void print(std::string message) {
		for (int i = 0; i < 15; i++) {
			std::cout << std::endl;
		}
		std::cout << "\t\t--------------------" << std::endl;
		std::cout << "\t\t" << toUpperCase(message) << std::endl;
		std::cout << "\t\t--------------------" << std::endl;
		for (int i = 0; i < 15; i++) {
			std::cout << std::endl;
		}
	}

};



