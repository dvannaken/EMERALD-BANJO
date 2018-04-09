#ifndef MapGen_hpp
#define MapGen_hpp
#include <time.h>
#include <cstdlib>
#include "RandomNum.h"
#include "Room.h"
#include "Corridor.h" 
#include <vector>
#include <iostream>
enum TileType { Wall, Floor};

class MapGen {

//TileType** tiles;
std::vector < std::vector<TileType> > tileBoard; // 2d vector 
//Room* rooms;
//Corridor* corridors;

std::vector<Room*> rooms;
std::vector<Corridor*> corridors;

public:
  int rows;
  int columns;

  RandomNum* numRooms = new RandomNum(15,20); // generates num of rooms between 15, 20
  RandomNum* roomWidth = new RandomNum(3,10);
  RandomNum* roomHeight = new RandomNum(3,10);
  RandomNum* corridorLength = new RandomNum(6,10); // how long the num of corridorLength will be

  MapGen(); //Constructor
  MapGen(int, int);
  void setupTileArray();

  void setupTileValuesForRooms();
  void SetupTilesValuesForCorridors();

  void createRoomAndCorridors(); 
  void debug();
  TileType getTile(int, int);
  /*void instantiateTiles();
  void instantiateOuterWalls();
  void instantiateVerticalOuterWall(float,float,float);
  void instantiateHorizontalOuterwall(float,float,float);
  void instantiateFromArray(float,float);*/

  ~MapGen();
	



};

#endif
