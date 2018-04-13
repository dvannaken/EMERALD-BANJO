#include "Entity.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;
}

float Entity::getX() const {
  return x;
}

float Entity::getY() const {
  return y;
}

void Entity::setX(int) {
  this->x = x;
}

void Entity::setY(int) {
  this->y = y;
}
