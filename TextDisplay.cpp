#include "TextDisplay.h"

#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

TextDisplay::TextDisplay() : MenuDisplay() {
	timeToDisplay = 0.0;
	lastT = 0.0;
}

TextDisplay::TextDisplay(double t, double x, double y, double w, double h) : MenuDisplay(1, x, y, w, h, true) {
	timeToDisplay = t;
	lastT = 0.0;
}

/*
TextDisplay::TextDisplay(unsigned n, double x, double y, double w, double h, bool v) : MenuDisplay(n, x, y, w, h, v) {
	timeToDisplay = 0.0;
	lastT = 0.0;
}
*/

TextDisplay::~TextDisplay() {}

void TextDisplay::newline(std::string s) {
	lastT = glutGet(GLUT_ELAPSED_TIME);
	rep = 0;

//	for (int i = maxlines - 1; i > 0; i--) {
//		lines.at(i) = lines.at(i-1);
//	}

	lines.at(0) = s;
}

void TextDisplay::display(double x, double y) {
	double t = glutGet(GLUT_ELAPSED_TIME);
    double delta = t - lastT;
	
	if ( delta < timeToDisplay ) {
		glColor3f(1, 0.1, 0);
		const char* c = lines.at(0).c_str();
//		double size = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c ) * w;
		double x_offset = 0.01 * rep;
		double y_offset = 0.005 * rep;

		glRasterPos2f(x + x_offset, y + y_offset);
//		std::cout << "offsets at " << x_offset << ", " << y_offset << std::endl;
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );

		rep++;
	}
	else
		rep = 0;
}

bool TextDisplay::isMoving() {
	return moving;
}
void TextDisplay::setTime(double t) {
	timeToDisplay = t;
}
void TextDisplay::setMoving(bool m) {
	moving = m;
}