#ifndef Room_HPP
#define Room_HPP
#include <iostream>
#include "RandomNum.h"
#include "Direction.h"
#include <algorithm>

class Corridor;

class Room { // I did not hit her, I DID Naught
	Corridor* c;
public:

	int xPos;
	int yPos;
	int roomWidth; 
	int roomHeight;
	Direction enteringCorridor;

  //int enteringCorridor;
	Room();
	void setupRoom(RandomNum*,RandomNum*,int,int);// first room
	void setupRoom(RandomNum*,RandomNum*,int,int, Corridor*);
	int clip(float,float,float);


};

#endif
