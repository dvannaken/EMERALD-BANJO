#ifndef Corridor_HPP
#define Corridor_HPP


#include "RandomNum.h"
#include <algorithm>


enum Direction {
	north, west, south, east
};
class Room;
class Corridor
{
	Room* r;
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

  Corridor();
  void setupCorridor(Room*, RandomNum*,RandomNum*,RandomNum*,int,int,bool);
  int clip(float, float, float);

private:

};


#endif
