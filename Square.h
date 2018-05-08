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
	monster
};

enum lootType { // the three types of loot available 
	_Empty,
	_Weapons,
	_Armors,
	_Potions
};
enum visibility {
	lightLevel_1,
	lightLevel_2,
	lightlevel_3,
	recentlyLit,
	litLevels,
	unknownLit
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

	
	lootType lootable; // dont know why it breaks my stuff when its private


	bool opaque;
	


    void draw();
	
	void _visited(bool);
	bool getVisited() const;
	bool inVision(); // utility function to see if the tile is in current vision

    entityType getEntityType() const;
    tileType getTile() const;
	visibility getVis();
	lootType getLootable();


	void setLootable(lootType);
	void setTile(tileType);
	void setVis(visibility);
	void setEntityType(entityType);
	void setColor(float, float, float);

    void clear();


    ~Square();
};

#endif
