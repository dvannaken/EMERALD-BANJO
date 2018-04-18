 #include <iostream>
#include <thread>
#include "Board.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Board::Board() {
	
	//generatoring new map

	
    float xinc = 0.04;
    float yinc = 0.04;
    float startx = -1;
    float starty = 1;
    for (int row = 0; row < 50; row++) {
        for (int col = 0; col < 50; col++) {
           /* if  (row == 0 || row == 49 || col == 0 || col == 49){
                squares.push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, 0, 0, 0));
            }*/
            squares.push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, .8, .8, .8)); //walls
        }
        
    }
    upToDate = true;
    inProgress = false;
    
   
    
    
   // delay = 1000;
}

Board::Board(int ii) {
	int size = ii;
	float xinc = 0.04;
	float yinc = 0.04;
	float startx = -1;
	float starty = 1;

	map = new MapGen(size,size);
	map->generate(random->randomInt(35,50));
	map->print();
	for (int row = 0; row < size; row++)
	{
		gameboard.push_back(std::vector<Square*>());
		for (int col = 0; col < size; col++)
		{
			// walls
			gameboard.at(row).push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, .8, .8, .8));
		}
	}

	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x)
			switch (map->getTile(x,y))
			{
			case MapGen::Unused:
				gameboard[x][y]->setTile(Unused);
				gameboard[x][y]->setColor(0, 0, 0);
				break;
			case MapGen::Floor:
				gameboard[x][y]->setTile(Floor);
				gameboard[x][y]->setColor(0.7, 0.7, 0.7);
				break;
			case MapGen::Corridor:
				gameboard[x][y]->setTile(Corridor);
				gameboard[x][y]->setColor(0.7, 0.7, 0.7);
				break;
			case MapGen::Wall:
				gameboard[x][y]->setTile(Wall);
				gameboard[x][y]->setColor(0.8, 0.8, 0.8);
				break;
			case MapGen::ClosedDoor:
				gameboard[x][y]->setTile(ClosedDoor);
				gameboard[x][y]->setColor(0.462, 0.423, 0.298);
				break;
			case MapGen::OpenDoor:
				gameboard[x][y]->setTile(OpenDoor);
				gameboard[x][y]->setColor(0.4, 0.4, 0.4);
				break;
			case MapGen::UpStairs:
				gameboard[x][y]->setTile(Upstairs);
				gameboard[x][y]->setColor(0.8, 0.1, 0.1);

				
			if (canMove(x - 1, y)) {
				player = new Player(x - 1, y); // spawns player left of upstairs
				gameboard[x - 1][y]->setEntityType(entityType::player);
			}
			else if (canMove(x, y - 1)) {
				player = new Player(x, y - 1); // spawns player right of upstairs
				gameboard[x - 1][y]->setEntityType(entityType::player);
			}
					
				
				break;
			case MapGen::DownStairs:
				gameboard[x][y]->setTile(Downstairs);
				gameboard[x][y]->setColor(0.8, 0.0, 0.0);
				break;
			default:
				break;
			}


	}

	upToDate = true;
	//inProgress = false;

}

void Board::draw() {

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{

			gameboard[i][j]->draw();

		}
	}
    catchUp();
}


void Board::handle(unsigned char key) {
	
	int playerX = player->getX();
	int playerY = player->getY();

	std::cout << playerX  << std::endl;
	std::cout << playerY  << std::endl;			
	if (key == 'a') {
		if (canMove(playerX, playerY - 1)) {
			std::cout << "moving up " << std::endl;
			std::cout << playerX << playerY << std::endl;
			player->moveUp();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			behind();
		}

	}
	if (key == 'w') {
		if (canMove(playerX - 1, playerY)) {
			std::cout << "moving left" << std::endl;
			player->moveLeft();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			behind();
		}
	}
	if (key == 's') {
		if (canMove(playerX + 1, playerY)) {
			std::cout << "moving down" << std::endl;
			player->moveRight();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			behind();
		}

	}
	if (key == 'd') {
		if (canMove(playerX, playerY + 1)) {
			std::cout << "moving right " << std::endl;
			player->moveDown();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			behind();
		}
	}
}




void Board::check(){
	//while (!gameover) {

	//	// game mechanics go here

	//}
	
}

void Board::reset(){
    counter = 0;
    /*for (int i = 0; i < squares.size(); i++) {
        squares[i]->clear();
    }*/
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			gameboard[i][j]->clear();
		}
	}
}

void Board::behind(){
    upToDate = false;
}

void Board::catchUp(){
    upToDate = true;
}

bool Board::isUpToDate() const {
    return upToDate;
}

bool Board::canMove(int endX, int endY)
{
	if (gameboard[endX][endY]->getTile() == Wall || gameboard[endX][endY]->getTile() == ClosedDoor)
	{
		return false;
	}
	else
		return true;
}


Board::~Board() {
	delete random;
	delete map;
	delete player;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			delete gameboard[i][j];
		}
	}
}
