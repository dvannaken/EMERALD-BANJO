#ifndef MenuDisplay_h
#define MenuDisplay_h

#include "Rect.h"
#include <string>
#include <vector>

class MenuDisplay : public Rect {
	bool visible;
	unsigned maxlines;
	std::vector < std::string > lines;

public:
    MenuDisplay();
    
	// (0.7, 0.9) is classic top-right corner
    MenuDisplay(unsigned, double, double, double, double, bool);
	
	~MenuDisplay();
	
	// moves text up, adds new line and removes oldest line
	void newline(std::string);
	
	//display all 3 text lines within? rect
	void display();
	
	bool isVisible();
	
	void toggleVisibility();
	void setMaxLines(unsigned);
};

#endif