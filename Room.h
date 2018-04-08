#ifndef Room_hpp
#define Room_hpp
#include "RandomNum.h"
#include "Corridor.h"
#include <algorithm>

class Room { // I did not hit her, I DID Naught

public:
  int xPos;
  int yPos;
  int roomWidth;
  int roomHeight;

  Direction enteringCorridor;
  Room(RandomNum*,RandomNum*,int,int);// first room
  Room(RandomNum*,RandomNum*,int,int,Corridor*);
  int clip(float,float,float);


};

#endif
