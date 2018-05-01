#ifndef Square_h
#define Square_h
#include "Rect.h"
#include "Player.h"
#include "TexRect.h"
#include "AnimatedRect.h"
//#include "GlutApp.h"
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
	empty, // the place is empty
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
  float mx;
  float my;
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

//graphics, just add more stuff here
  Square(const char* label, int x, int y, int w, int h);

  // These are the events we want to handle
  void draw();
  void keyPress(unsigned char key);
  void mouseDown(float x, float y);
  void mouseDrag(float x, float y);

  void specialKeyPress(int key);

  void specialKeyUp(int key);

  void redraw();

  TexRect* playerOne;
  TexRect* platform;
  AnimatedRect* gameOver;

  void idle(); //we do breathing here

  bool up;
  bool down;
  bool left;
  bool right;
  bool game_over;
  bool moving;



    ~Square();
};

#endif
