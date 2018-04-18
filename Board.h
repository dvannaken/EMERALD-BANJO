#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"
#include "MapGen.h"
#include <cmath>

typedef unsigned int uint;

static int multipliers[4][8] = {
	{ 1, 0, 0, -1, -1, 0, 0, 1 },
	{ 0, 1, -1, 0, 0, -1, 1, 0 },
	{ 0, 1, 1, 0, 0, -1, -1, 0 },
	{ 1, 0, 0, 1, -1, 0, 0, -1 }
	};

class Board {
	MapGen* map;
	Player* player;
	//CaveGen* cave;
    std::vector<Square*> squares;
	std::vector < std::vector<Square*> > gameboard; // 2d vector map
	RandomNum* random = new RandomNum();
    bool upToDate;
    bool inProgress;
    int stepCounter;
    int delay;
    
    void endTurn();
    void reset();
    
    void catchUp();
    void behind();

	//C++ shadowcasting implementation - Björn Bergström [bjorn.bergstrom@roguelikedevelopment.org]
	//with code from http://www.roguebasin.com/index.php?title=C%2B%2B_shadowcasting_implementation

	void setVisible(uint x, uint y, bool visible); //sets the visibility of the cell at the given position.
	bool isOpaque(uint x, uint y) const; //retruns whether the given position holds an opaque cell
	void castLight(uint x, uint y, uint radius, uint row, float startSlope, float endSlope, uint xx, uint xY, uint yx, uint yy);
    void doFov(uint x, uint y);
	void doFov(uint x, uint y,uint radius);
public:
    Board();
	Board(int);
    
    void draw();
    void handle(unsigned char);
    
    void check();
    
    bool isUpToDate() const;
	bool canMove(int,int);
    ~Board();
};

#endif
