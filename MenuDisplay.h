#ifndef MenuDisplay_h
#define MenuDisplay_h

#include "Rect.h"
#include <string>

class MenuDisplay : public Rect {
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	std::string s5;
	std::string s6;
	std::string s7;

public:
    MenuDisplay();
    
	// (0.7, 0.9) is classic top-right corner
    MenuDisplay(double, double);
	
	// moves text up, adds new line and removes oldest line
	void newline(std::string);
	
	//display all 3 text lines within? rect
	void display();
};

#endif