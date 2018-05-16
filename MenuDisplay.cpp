#include "MenuDisplay.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

MenuDisplay::MenuDisplay() : Rect() {
	s1 = "";
	s2 = "";
	s3 = "";
	s4 = "";
	s5 = "";
	s6 = "";
	s7 = "";
}

MenuDisplay::MenuDisplay(double x, double y) : Rect(x, y, 0.6, 0.4) {
	s1 = "";
	s2 = "";
	s3 = "";
	s4 = "";
	s5 = "";
	s6 = "";
	s7 = "";
}

void MenuDisplay::newline(std::string s) {
	s7 = s6;
	s6 = s5;
	s5 = s4;
	s4 = s3;
	s3 = s2;
	s2 = s1;
	s1 = s;
}

void MenuDisplay::display() {
	Rect::draw();
	
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
}