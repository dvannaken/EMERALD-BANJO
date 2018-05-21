#ifndef TextDisplay_h
#define TextDisplay_h

#include "MenuDisplay.h"

class TextDisplay : public MenuDisplay {
	double timeToDisplay;
	double lastT;
	bool moving;

public:
    TextDisplay();
    TextDisplay(double, double, double, double, double);
    //TextDisplay(unsigned, double, double, double, double, bool);
	
	~TextDisplay();
	
	void newline(std::string);

	void display(double, double);
	
	bool isMoving();
	void setTime(double);
	void setMoving(bool);
};

#endif