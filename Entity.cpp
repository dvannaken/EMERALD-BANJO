#include "Entity.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

float Entity::getX() const {
  return x;
}

float Entity::getY() const {
  return y;
}

void Entity::setX(float) {
  this->x = x;
}

void Entity::setY(float) {
  this->y = y;
}
