#ifndef Title_hpp
#define Title_hpp

#include "TexRect.h"
#include "AnimatedRect.h"

class Title {
	TexRect* dungeon;
    AnimatedRect* runner;
    AnimatedRect* gameOver;

public:
    Title();
	~Title();
	
	void draw();
	void animate(char);
	void advance(char);
	bool done(char);
};

#endif