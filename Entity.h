//should hold xy coordinates
#ifndef Entity_h
#define Entity_h

class Entity {
private:


public:
	int x;
	int y;
	Entity(int x, int y);

	float getX();
	float getY();

	void setX(int);
	void setY(int);
	
	virtual void draw() const {};

};


#endif
