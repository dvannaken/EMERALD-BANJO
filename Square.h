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
	lightLevel_1,
	lightLevel_2,
	lightlevel_3,
	recentlyLit,
	litLevels,
	unknownLit,
};


class Square : public Rect {
    Entity* entity;
    tileType tile;
	entityType entityTile; // need better name
	visibility vis;
	bool visited;
	
public:
    Square();
    Square(float);
    Square(float, float, float);
    Square(float, float, float, float, float, float);

	
	bool opaque;
	


    void draw() const;
	
	void _visited(bool);
	bool getVisited() const;

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
