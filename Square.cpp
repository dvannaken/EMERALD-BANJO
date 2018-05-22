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
	vis = unknownLit;
	lootable = _Empty;
	tile = Unused;
	entityTile = empty;
	visited = false;
}
Square::Square(float w) : Rect(0, 0, w, w){
	lootable = _Empty;
	tile = Unused;
	entityTile = empty;
	vis = unknownLit;
	visited = false;
}
Square::Square(float x , float y, float w) : Rect(x, y, w, w) {
	lootable = _Empty;
	tile = Unused;
	entityTile = empty;
	vis = unknownLit;
	visited = false;
}
Square::Square(float x, float y, float w, float r, float g, float b) : Rect(x, y, w, w, r, g, b) {
	lootable = _Empty;
	tile = Unused;
	entityTile = empty;
	vis = unknownLit;
	visited = false;
}

void Square::draw() {

	/*if (entityTile != empty) {
		entity->draw();
	}*/

	if (entityTile == player)
	{
		//std::cout << "Drawing Player" << std::endl;
		glColor3f(0.294, 0.466, 0.745);

		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);

		glEnd();
	}

	if (entityTile == monster && (vis == lightLevel_1 || vis == lightLevel_2 || vis == lightlevel_3) )
	{
		//std::cout << "Drawing Monster" << std::endl;
		glColor3f(0.420, 0.557, 0.137);

		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);
		glEnd();
	}

	if (lootable == _Weapons && inVision())
	{
		glColor3f(0.882, 0.545, 0.972);
		
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);

		glEnd();
	}

	if (lootable == _Armors && inVision())
	{
		glColor3f(0.768, 0.117, 0.945);

		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);

		glEnd();
	}
	if (lootable == _Potions && inVision())
	{
		glColor3f(0.454, 0.062, 0.556);

		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y - h);
		glVertex2f(x, y - h);

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
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);


    glEnd();

	

}


entityType Square::getEntityType() const {
    return entityTile;
}

tileType Square::getTile() const{
    return tile;
}

void Square::setLootable(lootType loot)
{
	this->lootable = loot;
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

bool Square::inVision() 
{
	return (vis == lightLevel_1 || vis == lightLevel_2 || vis == lightlevel_3);
}

void Square::_visited(bool visit){
	this->visited = visit;
}

visibility Square::getVis()
{
	return vis;
}

lootType Square::getLootable()
{
	return lootable;
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
