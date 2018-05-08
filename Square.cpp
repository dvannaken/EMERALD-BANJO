#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include "Square.h"


Square::Square() : Rect(){

	tile = Unused;
	entityTile = empty;
}
Square::Square(float w) : Rect(0, 0, w, w){

	tile = Unused;
	entityTile = empty;
}
Square::Square(float x , float y, float w) : Rect(x, y, w, w) {

	tile = Unused;
	entityTile = empty;
}
Square::Square(float x, float y, float w, float r, float g, float b) : Rect(x, y, w, w, r, g, b) {
	tile = Unused;
	entityTile = empty;
}

//graphic function
Square::Square(const char* label, int x, int y, int w, int h) {
	mx = 0.0;
	my = 0.0;

	playerPic = new TexRect("images/link2.png", 0, 0.67, 0.2, 0.2);
}


void Square::draw() const {

	/*if (entityTile != empty) {
		entity->draw();
	}*/

	if (entityTile == player)
	{
		std::cout << "Drawing Player" << std::endl;
		//this draw the blue-ish box for Player
		//need to put graphics on this part
		// Clear the screen
	 /*glClear(GL_COLOR_BUFFER_BIT);

	 // Set background color to black
	 glClearColor(0.0, 0.0, 1.0, 1.0);

	 // Set up the transformations stack
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();

		playerPic->draw();

	 glFlush();
	 glutSwapBuffers();*/

		glColor3f(0.294, 0.466, 0.745);

		glBegin(GL_POLYGON);
		glVertex2f(-y, -x);
		glVertex2f(-y, -(x + w));
		glVertex2f(-( y - h),-(x + w));
		glVertex2f(-(y - h),-x);

		glEnd();
	}

	if (vis < litLevels)
	{
		float darkness;
		switch (vis)
		{
		case lightLevel_1:
			darkness = -0.15;
			glColor3f(r, g , b + (darkness));
			break;
		case lightLevel_2:
			darkness = -0.2;
			glColor3f(r, g , b + (darkness));
			break;
		case lightlevel_3:
			darkness = -0.3;
			glColor3f(r, g , b + (darkness));
			break;
		case recentlyLit:
			darkness = 0.4;
			glColor3f(r - darkness, g - darkness, b - darkness);
			break;
		}

	}
	else
	{
		glColor3f(0, 0, 0);
	}


    glBegin(GL_POLYGON);
	glVertex2f(-y, -x);
	glVertex2f(-y, -(x + w));
	glVertex2f(-( y - h),-(x + w));
	glVertex2f(-(y - h),-x);


    glEnd();



}


Entity* Square::getEntityType() const {
    return entity;
}

tileType Square::getTile() const{
    return tile;
}

void Square::setTile(tileType t) {
	tile = t;
}

void Square::setVis(visibility vis)
{
	this->vis = vis;
}

bool Square::getVisited() const{
	return visited;
}

void Square::_visited(bool visit){
	this->visited = visit;
}

visibility Square::getVis()
{
	return vis;
}

void Square::setEntityType(entityType tile)
{
	entityTile = tile;
}

void Square::setColor(float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
}

void Square::clear() {
    if (entity != 0){
        delete entity;
			//	delete playerPic;
    }
    entity = 0;
	tile = Unused;
}

Square::~Square(){
    if (entity != 0){
        delete entity;
    }
}

void Square::keyPress(unsigned char key) {
	if(key == 27) { //escape key pressed
		delete playerPic;
		exit(0);
	}
}
