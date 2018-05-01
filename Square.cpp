#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include "Square.h"
//#include "TexRect.h"


//for the graphics
static Square* singleton;
void square_timer(int value) {
	if(singleton->game_over) {
		singleton->gameOver->advance(); //prints game over
	}

	if(singleton->moving) {
		singleton->playerOne->jump();
		float bx = singleton->playerOne->x + singleton->playerOne->w/2;
		float by = singleton->playerOne->y - singleton->playerOne->h + 0.1;
		if(singleton->platform->contains(bx, by)) {
			singleton->playerOne->rising = true;
			singleton->playerOne->yinc += 0.001;
			singleton->playerOne->xinc = singleton->playerOne->yinc;
			if(singleton->playerOne->yinc > 0.05) {
				singleton->playerOne->yinc = 0.05;
			}
		}
		if(singleton->playerOne->y - singleton->playerOne-> h < -0.99) {
			singleton->moving = false;
			singleton->game_over = true;
			singleton->gameOver->animate();
		}
	}
	if(singleton->up) {
		singleton->platform->moveUp(0.01);
	}
	if(singleton->down) {
		singleton->platform->moveDown(0.01);
	}
	if(singleton->left) {
		singleton->platform->moveLeft(0.01);
	}
	if(singleton->right) {
		singleton->platform->moveRight(0.01);
	}
	if(singleton->game_over) {
		singleton->redraw();
		glutTimerFunc(100, square_timer, value);
	}
	else {
		if(singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over) {
			singleton->redraw();
			glutTimerFunc(16, square_timer, value);
		}
	}
}

//graphics
Square::Square(const char* label, int x, int y, int w, int h) {
	singleton = this;
	mx = 0.0;
	my = 0.0;

//	platform = new TexRect("images/", -1, 1, 2, 2);
	playerOne = new TexRect("images/link.png", 0, 0.67, 0.2, 0.2);

}



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

void Square::draw() const {

	/*if (entityTile != empty) {
		entity->draw();
	}*/

	if (entityTile == player)
	{
		std::cout << "Drawing Player" << std::endl;
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
    }
    entity = 0;
	tile = Unused;
}

Square::~Square(){
    if (entity != 0){
        delete entity;
    }
}
