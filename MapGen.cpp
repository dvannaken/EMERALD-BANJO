#include "MapGen.h"

MapGen::MapGen() {
	setupTileArray();
	createRoomAndCorridors();
	setupTileValuesForRooms();
	SetupTilesValuesForCorridors();
	//instantiateTiles();
	//instantiateOuterWalls();
}

MapGen::MapGen(int column, int row) {

	std::cout << "constructing MapGen" << std::endl;
	columns = column;
	rows = row;
	setupTileArray();
	createRoomAndCorridors();
	setupTileValuesForRooms();
	SetupTilesValuesForCorridors();

}
void MapGen::setupTileArray()
{
	//failed implementations to clean up later
	/*tiles = new TileType[columns][];
	int size = *(&tiles+ 1) - tiles;
	for (int i = 0; i < size; i++)
	{
		tile[i] = new TileType[rows];
	}*/


	/*for (int i = 0; i < columns; i++)
	{
		
		tileBoard.push_back(std::vector<TileType>());
		for (int j = 0; j < rows; j++)
		{
			std::cout << "breaks here " << i<<  j << std::endl;
			tileBoard.at(j).push_back(Wall);
		}
	}*/

	tileBoard.resize(rows, std::vector<TileType>(columns, Wall));

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
		Room* currentRoom = rooms[i];

		// and for each through its width.

		for (int j = 0; j < currentRoom->roomWidth; j++)
		{
			int xCord = currentRoom->xPos + j;

			//for each horizontal tile, go up veritcally through the room's height
			for (int k = 0; k < currentRoom->roomHeight; k++)
			{
				int yCord = currentRoom->yPos + k;

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
