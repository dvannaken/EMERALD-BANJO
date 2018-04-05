#include <iostream>
#include <thread>
#include "Board.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// basic board drawing code from AK
Board::Board() {
	float xinc = .04;
	float yinc = .04;
	float startx = -1;
	float starty = 1;
	for (int row = 0; row < 50; row++) {
		for (int col = 0; col < 50; col++) {
			if (col == 49 || col == 0 || row == 0 || row == 49) {
				squares.push_back(new Square(startx + col * xinc, starty - row * yinc, .04, 0, 0, 0));
			}
			squares.push_back(new Square(startx + col * xinc, starty - row * yinc, .04, 1.0, 1.0, 1.0));
		}

	}
	upToDate = true;
	inProgress = false;

	lx = 0.0;
	ly = 0.0;
	cx = 0.0;
	cy = 0.0;
	rx = 0.0;
	ry = 0.0;

	//won = false;
	//done = false;
	counter = 0;

	delay = 1000;
}

void Board::draw() {
	if (1) {
		glLineWidth(4.0);
		glBegin(GL_LINES);

		glVertex2f(lx, ly);
		glVertex2f(cx, cy);

		glEnd();
		glLineWidth(2.0);
	}
	for (int i = 0; i < squares.size(); i++) {
		squares[i]->draw();
	}
	catchUp();
}

void Board::movementHandle(unsigned char key) {
	if (key == 'r') {
		reset();
	}
	if (key == 'w') {
		//setCvC();
	}
	if (key == 'a') {
		//setPvC();
	}
	if (key == 's') {
		//setPvP();
	}
	if (key == 'd') {
		//
	}
}


void Board::check() {
}


void Board::endTurn() {
}

void Board::reset() {
	counter = 0;
	for (int i = 0; i < squares.size(); i++) {
		squares[i]->clear();
	}
}

void Board::behind() {
	upToDate = false;
}

void Board::catchUp() {
	upToDate = true;
}

bool Board::isUpToDate() const {
	return upToDate;
}

Board::~Board() {
	for (int i = 0; i < squares.size(); i++) {
		delete squares[i];
	}
}
