#ifndef Corridor_HPP
#define Corridor_HPP

#include <iostream>
#include "RandomNum.h"
#include "Direction.h"
#include <algorithm>


class Room;
class Corridor
{
	Room* r;
public:

  int startX;
  int startY;
  int corridorLength;

  Direction direction;

  
  int endX; 
  int endY;
  int getEndX();
  int getEndY();

  Corridor();
  void setupCorridor(Room*, RandomNum*,RandomNum*,RandomNum*,int,int,bool);
  int clip(float, float, float);
  void debug();
private:

};


#endif
