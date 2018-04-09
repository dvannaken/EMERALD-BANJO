#include "MapGen.h"

MapGen::MapGen() {
	setupTileArray();
	createRoomAndCorridors();
	setupTileValuesForRooms();
	SetupTilesValuesForCorridors();
	//instantiateTiles();
	//instantiateOuterWalls();
}

void MapGen::setupTileArray()
{
	tiles = new TileType[columns][];
	int size = *(&tiles+ 1) - tiles;
	for (int i = 0; i < size; i++)
	{
		tile[i] = new TileType[rows];
	}
}

void MapGen::createRoomAndCorridors() {
	//create the rooms array with a random size.

	rooms = new Room[numRooms->genRandom];

	// there should one less corridor than there are rooms;
	int roomSize = *(&rooms + 1) - rooms;

	corridors = new Corridor[roomSize - 1];

	int corrSize = *(&corridors + 1) - corridors;
	// create first room and corridor;

	rooms[0] = new Room();
	corridors[0] = new Corridor();

	//setting up the first room
	rooms[0]->setupRoom(roomWidth, roomHeight, columns, rows);
	corridors[0]->setupCorridor(room[0], corridorLength, roomWidth, roomHeight, columns, rows, true);

	for (int i = 1; i < roomSize; i++)
	{
		rooms[i] = new Room();
		// set up the room based n the previous corridor 
		rooms[i].setupRoom(roomWidth, roomHeight, columns, rows, corridors[i - 1]);

		if (i < corrSize )	
		{
			corridors[i] = new Corridor();
			corridors[i]->setupCorridor(rooms[i], corridorLength, roomWidth, roomHeight, columns, rows, false);
		}

		if (i == roomSize * .5) {
			// todo place player at a position
			//set player location at rooms[i]->xPos, rooms[i]->yPos
		}

	}
}


void MapGen::setupTileValuesForRooms()
{
	int roomSize = *(&rooms + 1) - rooms;
	for (int  i = 0; i < length; i++)
	{
		Room* currentRoom = room[i];

		// and for each through its width.

		for (int j = 0; j < currentRoom->roomWidth; j++)
		{
			int xCord = currentRoom->xPos + j;

			//for each horizontal tile, go up veritcally through the room's height
			for (int k = 0; k < currentRoom->roomHeight; k++)
			{
				int yCord = currentRoom->yPos + k;

				// the coordinates in the jagged array are based on the room's position and its width and height.

				tiles[xCord][yCord] = Floor;
			}
		}
	}
}

void MapGen::SetupTilesValuesForCorridors() {
	// go through every corridor...
	int corrSize = *(&corridors + 1) - corridors;
	for (int i = 0; i < corrSize; i++)
	{
		Corridor* currentCorridor = corridors[i];

		for (int j = 0; j < currentCorridor->corridorLength; j++)
		{
			int xcord = currentCorridor->startX;
			int ycord = currentCorridor->startY;

			// depending on direction add or subtract from appropriate cords
			// based on on how far through the length the loop is.

			switch (currentCorridor->direction) 
				{
			case north:
				ycord += j;
				break;
			case east:
				////xcord += j;
				break;
			case south:
				ycord -= j;
				break;
			case west:
				xcord -= j;
				break;
			default:
				break;
			}
			tiles[xcord][ycord] = Floor;
		}
	}
}

//MapGen::instantiateTiles() {
//	int rows = sizeof tiles / sizeof tiles[0];
//	int cols = sizeof tiles[0] / sizeof(TileType);
//	int size = rows * cols;
//	for (int i = 0; i < rows; i++)
//	{
//		cols = sizeof tiles[0] / sizeof(TileType);
//		for (int j = 0; j < cols; j++)
//		{
//
//		}
//	}
//
//
//}
