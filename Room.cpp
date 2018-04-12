#include "Room.h"
#include "Corridor.h"
#include <cmath>

Room::Room() {
}
void Room::setupRoom(RandomNum* widthRange, RandomNum* heightRange,int cols, int rows){
	//  set a random width and height
	roomWidth = widthRange->genRandom();
	roomHeight = heightRange->genRandom();
	// sets the x and y cords so the room is roughly in the middle
	xPos = int((cols / 2.0) - (roomWidth /2.0));
	yPos = int((rows /2.0) - (roomHeight / 2.0));

}

void Room::setupRoom(RandomNum* widthRange,RandomNum* heightRange, int columns, int rows, Corridor* corridor){
enteringCorridor = corridor->direction;  // set the entering corridor directions

// random vals for height and width

roomWidth = widthRange->genRandom();
roomHeight = heightRange->genRandom();
std::cout << "room Direction " << (Direction)corridor->direction << std::endl;
switch(corridor->direction){
	// if its going north
	case north:
	// ... the height of the room mustn't go beyond the board so it must be clamped based
	// on the height of the board (rows) and the end of corridor that leads to the room.
		roomHeight = clip(roomHeight,1,rows - corridor->getEndY());
	// the y coordinate of a room must be at the end of the corridor since the corridor leads to the bottem of the room.
		yPos = corridor->getEndY();

		// the x cord can be random but the left most possible is no further away then the width
		// and the right most possibility is that the end of the corridor is at the positon of the room

		xPos = widthRange->genRandom(corridor->getEndX() - roomWidth + 1, corridor->getEndX());
		// this must be clamped to ensure that the room dosent go off the board

		xPos = clip(xPos,0, columns - roomWidth);
		break;
	case east:
		roomWidth = clip(roomWidth, 1, columns - corridor->getEndX());
		xPos = corridor->getEndX();

		yPos = widthRange->genRandom(corridor->getEndY() - roomHeight + 1, corridor->getEndY());
		yPos = clip(yPos,0,rows - roomHeight);
		break;

	case south:
		roomHeight = clip(roomHeight, 1 , corridor->getEndY());
		yPos = corridor->getEndY() - roomHeight + 1;

		xPos = widthRange->genRandom(corridor->getEndX() - roomWidth + 1, corridor->getEndX());
		xPos = clip(xPos,0,columns - roomWidth);
		break;
	case west:
		roomWidth = clip(roomWidth, 1, corridor->getEndX());
		xPos = corridor->getEndX() - roomWidth + 1;

   		yPos = widthRange->genRandom(corridor->getEndY() - roomHeight + 1, corridor->getEndY());
		yPos = clip(yPos, 0, rows - roomHeight);
    break;
}


}

int Room::clip(float n, float lower, float upper) { // clips a bound from lower to upeper
	return std::max(lower, std::min(n, upper));
}
