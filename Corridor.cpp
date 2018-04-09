#include "Corridor.h"
#include "Room.h"
Corridor::Corridor() {

}
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

      Direction oppositeDirection = (Direction)(((int)room->enteringCorridor + 2) % 4);

	  // if this is the not the first corridor and the randomly selected direction is oppoiste to the previous orridor's direction..

	  if (!firstCorridor && direction == oppositeDirection)
	  {
		  // Rotate the direction 90 degrees clockwise (North becomes East, East becomes South, etc).
		  // This is a more broken down version of the opposite direction operation above but instead of adding 2 we're adding 1.
		  // This means instead of rotating 180 (the opposite direction) we're rotating 90.

		  int directionInt = int(direction);
		  directionInt++;
		  directionInt = directionInt % 4;
		  direction = (Direction)directionInt;
	  }
	  // setting a random length
	  corridorLength = length->genRandom();

	  // creating a cap for how long the length can be(this will be changed based on the direction of position)
	  int maxLength = length->genRandom();

	  switch (direction) {
	  case north:
		  // if starting pos is in the x axis can be random by within the width of the room
		
		  startX = length->genRandom(room->xPos, room->xPos + room->roomWidth - 1);

		  // the starting position in the y asis must be at the top of the room

		  startY = room->yPos + room->roomHeight;
		  // the maximum length of the corridor can be the is the height of the board rows but from the top of the room ( ypos + height)
		  maxLength = rows - startY - roomHeight->getMinNum();
		  break;
	  case south:
		  startX = length->genRandom(room->xPos, room->xPos + room->roomWidth);
		  startY = room->yPos;
		  maxLength = startY - roomWidth->getMinNum();
		  break;
	  case west:
		  startX = room->xPos;
		  startY = length->genRandom(room->yPos, room->yPos + room->roomHeight);
		  maxLength = startX - roomWidth->getMinNum();
		  break;
	  case east:
		  startX = room->xPos + room->roomWidth;
		  startY = length->genRandom(room->yPos, room->yPos + room->roomHeight - 1);
		  maxLength = columns - startX - roomWidth->getMinNum();
		  break;
	  default:

		  // should never get here
		  break;
	  }
	 
	  corridorLength = clip(corridorLength, 1, maxLength);

}

int Corridor::clip(float n, float lower, float upper) { // clips a bound from lower to upeper
	return std::max(lower, std::min(n, upper));
}
