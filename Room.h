#ifndef Room_HPP
#define Room_HPP


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
  Room();
  void setupRoom(RandomNum*,RandomNum*,int,int);// first room
  void setupRoom(RandomNum*,RandomNum*,int,int,Corridor*);
  int clip(float,float,float);


};

#endif
