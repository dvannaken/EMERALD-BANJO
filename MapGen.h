#ifndef MapGen_HPP
#define MapGen_HPP
#include <vector>
#include <iostream>
#include "RandomNum.h"
#include <random>


/*

	This map generation implmentation came from an open source website rougebasin, which heavely came from user underww on the site.
	http://www.roguebasin.com/index.php?title=Dungeon-Building_Algorithm


*/

struct Rectangle{
    int x,y;
    int width, height;
};

class MapGen{
public:
    enum Tile{
		Unused		= ' ',
		Floor		= '.',
		Corridor	= ',',
		Wall		= '#',
		ClosedDoor	= '+',
		OpenDoor	= '-',
		UpStairs	= '<',
		DownStairs	= '>',
		TileCount
    };
    enum Direction{
        North,
        South,
        West,
        East,
        DirectionCount
    };

    MapGen(int,int);
    void generate(int);
    void print();
	char getTile(int, int) const;
	~MapGen();
private:
    
    RandomNum* rng = new RandomNum();

    int _width;
    int _height;

    std::vector < std::vector<Tile> > tileBoard; // 2d vector 
    std::vector<char> _tiles;
    std::vector<Rectangle> _rooms;
    std::vector<Rectangle> _exits;

    void setTile(int, int, char);
    bool createFeature();
    bool createFeature(int, int, Direction);
    bool makeRoom(int, int, Direction,bool);
    bool makeCorridor(int,int, Direction);
    bool placeRect(const Rectangle&, char);
    bool placeObject(char);
    

};


#endif