#include "Corridor.h"

int Corridor::getEndX(){
  if (direction == north || direction == south){
    return startX;
  }
  if (direction == east) {
    return startX + corridorLength -1;
  }
  return startX - corridorLength + 1;
}
int Corridor::getEndY(){
  if (direction == east || direction == west){
    return startY;
  }
  if (direction == north ) {
    return startY + corridorLength -1;
  }
  return startY + corridorLength + 1;
}
void Corridor::setupCorridor(Room* room, RandomNum* length, RandomNum* roomWidth,
   RandomNum* roomHeight,int columns, int rows, bool firstCorridor){

     // generate a random number 0,3 for the cardinal directions
     direction = (Direction)length->genRandom(0,4);

     // Find the direction opposite to the one entering the room this corridor is leaving from.
        // Cast the previous corridor's direction to an int between 0 and 3 and add 2 (a number between 2 and 5).
        // Find the remainder when dividing by 4 (if 2 then 2, if 3 then 3, if 4 then 0, if 5 then 1).
        // Cast this number back to a direction.
        // Overall effect is if the direction was South then that is 2, becomes 4, remainder is 0, which is north

      Direction oppositeDirection = (Direction)(((int)room.enteringCorridor + 2) % 4);



}
