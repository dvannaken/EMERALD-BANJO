#include "Bar.h"

#include <iostream>

Bar::Bar() {
	border = new Rect();
	max = new Rect();
	percent = new Rect();
}

Bar::Bar(float x, float y, float w, float h) {
	border = new Rect(x, y, w, h, 1, 1, 1);		//black
	max = new Rect(x, y, w, h, 1, 0, 0);		//red
	percent = new Rect(x, y, w, h, 0, 1, 0);	//green
}

Bar::~Bar() {
	delete border;
	delete max;
	delete percent;
}

void Bar::setPercent(double change) {
	float diff = max->getW() * change;
	percent->setW(diff);
}

// percemt on top of max
void Bar::draw() {
	border->draw(false);
	percent->draw(true);
	max->draw(true);
}