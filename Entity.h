//should hold xy coordinates
#ifndef Entity_h
#define Entity_h

class Entity {
private:
	int x;
	int y;

public:

	Entity(int x, int y);

	float getX() const;
	float getY() const;

	void setX(int);
	void setY(int);

};


#endif
