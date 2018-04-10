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

Board::Board() {
	
	//generatoring new map

	
    float xinc = 0.04;
    float yinc = 0.04;
    float startx = -1;
    float starty = 1;
    for (int row = 0; row < 50; row++) {
        for (int col = 0; col < 50; col++) {
           /* if  (row == 0 || row == 49 || col == 0 || col == 49){
                squares.push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, 0, 0, 0));
            }*/
            squares.push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, .8, .8, .8));
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
    
    
   // delay = 1000;
}

Board::Board(int ii) {
	int size = ii;
	float xinc = 0.04;
	float yinc = 0.04;
	float startx = -1;
	float starty = 1;

	generator = new MapGen(ii, ii);
	generator->debug();
	for (int row = 0; row < size; row++)
	{
		gameboard.push_back(std::vector<Square*>());
		for (int col = 0; col < size; col++)
		{
			if (row == 0 || row == 49 || col == 0 || col == 49) {
				gameboard.at(row).push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, 0, 0, 0));
			}
			gameboard.at(row).push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, .8, .8, .8));
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (generator->getTile(i,j) == Floor)
			{
				gameboard[i][j]->setTile(f);
				gameboard[i][j]->setColor(0.9, 0.9, 0.9);
			}
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
}

void Board::draw() {
    if (1){
        glLineWidth(4.0);
        glBegin(GL_LINES);
        
        glVertex2f(lx, ly);
        glVertex2f(cx, cy);
        
        glEnd();
        glLineWidth(2.0);
    }
    /*for (int i = 0; i < squares.size(); i++) {
        squares[i]->draw();
    }*/


	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{

			gameboard[i][j]->draw();
		}
	}
    catchUp();
}


void Board::handle(unsigned char key) {
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
	if (key == 'd'){
	}
}

void Board::check(){

}

void Board::reset(){
    counter = 0;
    /*for (int i = 0; i < squares.size(); i++) {
        squares[i]->clear();
    }*/
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			gameboard[i][j]->clear();
		}
	}
}

void Board::behind(){
    upToDate = false;
}

void Board::catchUp(){
    upToDate = true;
}

bool Board::isUpToDate() const {
    return upToDate;
}


Board::~Board() {
   /* for (int i = 0; i < squares.size(); i++) {
        delete squares[i];
    }*/
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			delete gameboard[i][j];
		}
	}
}
