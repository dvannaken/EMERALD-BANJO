//should hold xy coordinates
#ifndef Entity_h
#define Entity_h

#include "TexRect.h"

class Entity {
	TexRect* objectTex;

public:
	int x;
	int y;
	Entity(int, int);
	~Entity();

	float getX();
	float getY();

	void setX(int);
	void setY(int);
	
	void draw();

};


#endif
