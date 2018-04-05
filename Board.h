#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"

class Board {
    std::vector<Square*> squares;
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
    
    void draw();
    void handle(float, float);
    void handle(unsigned char);
    
    void check();
    
    bool isUpToDate() const;
    
    ~Board();
};

#endif
