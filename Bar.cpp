#include "Bar.h"

#include <string>

Bar::Bar() {
	border = new Rect();
	max = new Rect();
	percent = new Rect();
}

Bar::Bar(float x, float y, float w, float h, std::string type) {
	if (type == "health") {
		border = new Rect(x, y, w, h, 1, 1, 1);		//white
		max = new Rect(x, y, w, h, 1, 0, 0);		//red
		percent = new Rect(x, y, w, h, 0, 1, 0);	//green
	}
	else if (type == "exp") {
		border = new Rect(x, y, w, h, 1, 1, 1);		//white
		max = new Rect(x, y, w, h, 0, 0, 0);		//black
		percent = new Rect(x, y, w, h, 1, 0, 1);	//purple
	}
	else if (type == "mana") {
		border = new Rect(x, y, w, h, 1, 1, 1);		//white
		max = new Rect(x, y, w, h, 0, 0, 0);		//black
		percent = new Rect(x, y, w, h, 0, 0, 1);	//blue
	}
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