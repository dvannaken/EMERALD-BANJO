#ifndef Bar_h
#define Bar_h

#include <string>
#include "Rect.h"

class Bar {
	Rect* border;
	Rect* max;
	Rect* percent;

public:
    Bar();
	Bar(float, float, float, float, std::string);
	~Bar();
	
	void setPercent(double);

	void draw();
};

#endif