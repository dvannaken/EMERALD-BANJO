#ifndef Square_h
#define Square_h
#include "Rect.h"
#include "Player.h"

enum tileType {
    Unused,
    Floor,
    Corridor,
    Wall,
    ClosedDoor,
    OpenDoor,
    Upstairs,
    Downstairs
}; 

enum entityType {
	empty,
	player,
	item,
};


class Square : public Rect {
    Entity* entity;
    tileType tile;
	entityType entityTile; // need better name
public:
    Square();
    Square(float);
    Square(float, float, float);
    Square(float, float, float, float, float, float);

    void draw() const;
	

    Shape* getEntityType() const;
    tileType getTile() const;
	void setTile(tileType);
	void setColor(float, float, float);

    void clear();


    ~Square();
};

#endif
