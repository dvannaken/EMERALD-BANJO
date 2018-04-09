#ifndef Corridor_HPP
#define Corridor_HPP
#include "RandomNum.h"
#include <algorithm>
#include "Room.h"


enum Direction {
	north, south, west, east
};

class Corridor{
public:
  int startX;
  int startY;
  int corridorLength;
  Direction direction;
  int facing;
  int endX; 
  int endY;
  int getEndX() ;
  int getEndY();

  void setupCorridor(Room*, RandomNum*,RandomNum*,RandomNum*,int,int,bool);
  int clip(float, float, float);

};


#endif
