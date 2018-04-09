#ifndef MapGen_hpp
#define MapGen_hpp
#include <time.h>
#include <cstlib>
#include "RandomNum.h"
#include "Room.h"
#include "Corridor.h"
enum TileType { Wall, Floor};

class MapGen {

TileType** tiles;
Room* rooms;
Corridor* corridors;

public:
  int row;
  int columns;

  RandomNum* numRooms = new RandomNum(15,20); // generates num of rooms between 15, 20
  RandomNum* roomWidth = new RandomNum(3,10);
  RandomNum* roomHeight = new RandomNum(3,10);
  RandomNum* corridorLength = new RandomNum(6,10); // how long the num of corridorLength will be

  MapGen(); //Constructor

  void setupTileArray();

  void setupTileValuesForRooms();
  void SetupTilesValuesForCorridors();

  void createRoomAndCorridors();

  /*void instantiateTiles();
  void instantiateOuterWalls();
  void instantiateVerticalOuterWall(float,float,float);
  void instantiateHorizontalOuterwall(float,float,float);
  void instantiateFromArray(float,float);*/

  ~MapGen();




};

#endif
