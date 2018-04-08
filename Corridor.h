#ifndef Corridor_hpp
#define Corridor_hpp
#include "RandomNum.h"
#include "Room.h"
enum Direction {
   north,south,west,east
 };

class Corridor{
public:
  int startX;
  int startY;
  int corridorLength;
  Direction direction;
  int endX; //get idk
  int endY;
  int getEndX() ;
  int getEndY();

  void setupCorridor(Room*, RandomNum*,RandomNum*,RandomNum*,int,int,bool);


};
#endif
