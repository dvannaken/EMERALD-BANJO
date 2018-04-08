#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"

class Board {
    std::vector<Square*> squares;
	std::vector < std::vector<Square*> > gameboard; // 2d vector map
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
