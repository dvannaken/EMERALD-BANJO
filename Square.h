#ifndef Square_h
#define Square_h
#include "Rect.h"
#include "Player.h"
#include <algorithm>

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
	empty, // the palce is empty
	player,
	monster,
	item,
	items
};
enum visibility {
	currentlyLit = 0,
	recentlyLit = 1,
	furtherLit = 20,
	fartherLit = 30,
	litLevels = 40,
	unknown = 50,
};


class Square : public Rect {
    Entity* entity;
    tileType tile;
	entityType entityTile; // need better name
	visibility vis;
	
public:
    Square();
    Square(float);
    Square(float, float, float);
    Square(float, float, float, float, float, float);

	bool visible;
	bool opaque;
	


    void draw() const;
	

    Entity* getEntityType() const;
    tileType getTile() const;
	void setTile(tileType);
	void setVis(visibility);
	visibility getVis();
	void setEntityType(entityType);
	void setColor(float, float, float);

    void clear();


    ~Square();
};

#endif
