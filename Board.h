#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"
#include "MapGen.h"

class Board {
	MapGen* map;
	//CaveGen* cave;
    std::vector<Square*> squares;
	std::vector < std::vector<Square*> > gameboard; // 2d vector map
	RandomNum* random = new RandomNum();
    float lx, ly, cx, cy, rx, ry;
    bool upToDate;
    bool inProgress;
    int counter;
    int delay;
    
    void endTurn();
    void reset();
    
    void catchUp();
    void behind();
    
public:
    Board();
	Board(int);
    
    void draw();
    void handle(unsigned char);
    
    void check();
    
    bool isUpToDate() const;
    
    ~Board();
};

#endif
