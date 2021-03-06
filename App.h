#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "TexRect.h"
#include <cmath>

#include "GlutApp.h"
#include "Board.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    Board* gameBoard;
    
    Board game;
    void menuScreen();
    void gameScreen();

    int t;
    int lastT;
    double delta;
    
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    void idle();

    void running();
    
    TexRect* dungeon;
    TexRect* runner;
};

#endif
