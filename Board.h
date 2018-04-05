#ifndef Board_h
#define Board_h
#include <vector>
#include "Square.h"

class Board {
	std::vector<Square*> squares;
	float lx, ly, cx, cy, rx, ry;
	//Turn turn;
	//Player player;
	bool upToDate;
	bool inProgress;
	int counter;
	int delay;

	void endTurn();
	void reset();

	void catchUp();
	void behind();

	//void checkForVictory();

	//int selectMove(Turn);

public:
	Board();

	void draw();

	void check();

	bool isUpToDate() const;
	void movementHandle(unsigned char);

	~Board();
};

#endif