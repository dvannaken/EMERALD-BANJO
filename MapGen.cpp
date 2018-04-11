#include "MapGen.h"

MapGen::MapGen() {
	setupTileArray();
	createRoomAndCorridors();
	setupTileValuesForRooms();
	SetupTilesValuesForCorridors();
	//instantiateTiles();
	//instantiateOuterWalls();
}

MapGen::MapGen(int column, int row, mapType map) {

if(map == Cave){
	fillPercent = 50;
	columns = column;
	rows = row;
	setupTileArray();
	randomFillMap();

	for (int i = 0; i < 3; i++)
	{
		smoothMap();
	}
	


}
else{
	std::cout << "constructing MapGen" << std::endl;
	columns = column;
	rows = row;
	setupTileArray();
	createRoomAndCorridors();
	setupTileValuesForRooms();
	SetupTilesValuesForCorridors();

}
	
}
void MapGen::setupTileArray()
{
	tileBoard.resize(rows, std::vector<TileType>(columns, Wall));

}

void MapGen::randomFillMap()
{
	RandomNum * rand = new RandomNum(0, 100);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int num = rand->genRandom();
			if (i == 0 || j == 0 || i == 49 || j == 49) {
				tileBoard[i][j] == Wall;
			}
			else if (num < fillPercent)
			{
				tileBoard[i][j] = Floor;
			}
			else tileBoard[i][j] = Wall;
		}
	}
	delete rand;
}

int MapGen::getSurroundingWallsCount(int gridX, int gridY) {
	int wallCount = 0;
	for (int neighbourX = gridX - 1; neighbourX <= gridX + 1; neighbourX++) {

		for (int neighbourY = gridY - 1; neighbourY <= gridY + 1; neighbourY++) {

			if (neighbourX >= 0 && neighbourX < rows && neighbourY >= 0 && neighbourY < columns) {
				if (neighbourX != gridX || neighbourY != gridY) {

					if (tileBoard[neighbourX][neighbourY] == Wall) {

						wallCount++;
					}

				}
			}
			else {
				wallCount++;
			}
		}
	}
	std::cout << wallCount << std::endl;
	return wallCount;
}

void MapGen::smoothMap() {
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			int neighbourWallTiles = getSurroundingWallsCount(x, y);

			if (neighbourWallTiles > 4)
				tileBoard[x][y] = Wall;
			else if (neighbourWallTiles < 4)
				tileBoard[x][y] = Floor;

		}
	}

}

void MapGen::createRoomAndCorridors() {
	//create the rooms array with a random size.
	//rooms = new Room[numRooms->genRandom];
	for (int i = 0; i < numRooms->genRandom(); i++)
	{
		rooms.push_back(new Room());
	}
	

	// there should one less corridor than there are rooms;
	//corridors = new Corridor[roomSize - 1];

	for (int i = 0; i < rooms.size()-1; i++)
	{
		corridors.push_back(new Corridor());
	}

	//rooms[0] = new Room();
	//corridors[0] = new Corridor();
	//setting up the first room
	rooms[0]->setupRoom(roomWidth, roomHeight, columns, rows);

	corridors[0]->setupCorridor(rooms[0], corridorLength, roomWidth, roomHeight, columns, rows, true);

	for (int i = 1; i < rooms.size(); i++)
	{
		// set up the room based n the previous corridor 
		rooms[i]->setupRoom(roomWidth, roomHeight, columns, rows, corridors[i - 1]);

		if (i < corridors.size() )	
		{
			//corridors[i] = new Corridor();
			corridors[i]->setupCorridor(rooms[i], corridorLength, roomWidth, roomHeight, columns, rows, false);
		}

		if (i == rooms.size() * .5) {
			// todo place player at a position
			//set player location at rooms[i]->xPos, rooms[i]->yPos
		}

	}
}

void MapGen::debug()
{
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (tileBoard[i][j] == Floor)
			{
				std::cout << "x";
			}
			else if(tileBoard[i][j] == Wall)
			{
				std::cout << " ";
			}
		}
		std::cout << "" << std::endl;
	}
}

TileType MapGen::getTile(int i, int j)
{
	return tileBoard[i][j];
}

MapGen::~MapGen()
{
	delete numRooms;
	delete roomHeight;
	delete roomWidth;
	delete corridorLength;

	for (int i = 0; i < rooms.size(); i++)
	{
		delete rooms[i];
	}
	for (int i = 0; i < corridors.size(); i++)
	{
		delete corridors[i];
	}
}


void MapGen::setupTileValuesForRooms()
{
	//int roomSize = *(&rooms + 1) - rooms;
	for (int  i = 0; i < rooms.size(); i++)
	{
		//Room* currentRoom = rooms[i];

		// and for each through its width.

		for (int j = 0; j < rooms[i]->roomWidth; j++)
		{
			int xCord = rooms[i]->xPos + j;

			//for each horizontal tile, go up veritcally through the room's height
			for (int k = 0; k < rooms[i]->roomHeight; k++)
			{
				int yCord = rooms[i]->yPos + k;

				// the coordinates in the jagged array are based on the room's position and its width and height.

				tileBoard[xCord][yCord] = Floor;
			}
		}
	}
}

void MapGen::SetupTilesValuesForCorridors() {
	// go through every corridor...
	//int corrSize = *(&corridors + 1) - corridors;
	for (int i = 0; i < corridors.size(); i++)
	{
		//Corridor* corridors = corridors[i];

		for (int j = 0; j < corridors[i]->corridorLength; j++)
		{
			int xcord = corridors[i]->startX;
			int ycord = corridors[i]->startY;

			// depending on direction add or subtract from appropriate cords
			// based on on how far through the length the loop is.
			std::cout << "Corridor " << i << " " << corridors[i]->startX << " " <<  corridors[i]->startY << corridors[i]->getEndX() << " "<< corridors[i]->getEndY() << " " << corridors[i]->corridorLength << " "<< corridors[i]->direction << std::endl;
			switch (corridors[i]->direction) 
				{
			case north:
				ycord += j;
				break;
			case east:
				xcord += j;
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
			tileBoard[xcord][ycord] = Floor;
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
