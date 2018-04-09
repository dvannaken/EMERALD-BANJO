#ifndef Square_h
#define Square_h

#include "Rect.h"
enum tileType {wall, f, d}; // wall, floor, door

class Square : public Rect {
    Shape* symbol;
    tileType tile;
public:
    Square();
    Square(float);
    Square(float, float, float);
    Square(float, float, float, float, float, float);

    void draw() const;
	

    Shape* getSymbol() const;
    tileType getTile() const;
	void setTile(tileType);
	void setColor(float, float, float);

    void clear();

    void handle(float x, float y);

    ~Square();
};

#endif
