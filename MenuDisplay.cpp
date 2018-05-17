#include "MenuDisplay.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

MenuDisplay::MenuDisplay() : Rect() {
	maxlines = 1;
	lines.push_back("");
}

MenuDisplay::MenuDisplay(unsigned n, double x, double y, double w = 0.6, double h = 0.4) : Rect(x, y, w, h) {
	maxlines = n;
	for (int i = 0; i < maxlines; i++) {
		lines.push_back("");
	}
}

void MenuDisplay::setMaxLines(unsigned n) {
	for (int i = maxlines; i < n; i++) {
		lines.push_back("");
	}
	maxlines = n;
}

void MenuDisplay::newline(std::string s) {
	for (int i = maxlines - 1; i > 0; i--) {
		lines.at(i) = lines.at(i-1);
	}

	lines.at(0) = s;
}

void MenuDisplay::display() {
	Rect::draw();
	
	float offset = (maxlines * 0.05);
	for (int i = 0; i < maxlines; i++) {
		glRasterPos2f(x + 0.01, y - offset);
		const char* c = lines.at(i).c_str();
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
		offset -= 0.05;
	}
/*	
	glRasterPos2f(x + 0.01, y - 0.05);
	const char* c = s7.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.10);
	c = s6.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.15);
	c = s5.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.20);
	c = s4.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.25);
	c = s3.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.30);
	c = s2.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
	
	glRasterPos2f(x + 0.01, y - 0.35);
	c = s1.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)c );
*/
}