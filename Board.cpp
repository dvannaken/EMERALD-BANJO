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

Board::Board()
{

	//generatoring new map

	float xinc = 0.04;
	float yinc = 0.04;
	float startx = -1;
	float starty = 1;
	for (int row = 0; row < 50; row++)
	{
		for (int col = 0; col < 50; col++)
		{
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

Board::Board(int ii)
{
	int size = ii;
	float xinc = 0.04;
	float yinc = 0.04;
	float startx = -1;
	float starty = 1;

	loot = new ItemManger();
	map = new MapGen(size, size);
	map->generate(random->randomInt(35, 50));
	map->print();
	for (int row = 0; row < size; row++)
	{
		gameboard.push_back(std::vector<Square *>());
		for (int col = 0; col < size; col++)
		{
			// walls
			gameboard.at(row).push_back(new Square(startx + col * xinc, starty - row * yinc, 0.04, .8, .8, .8));
		}
	}

	for (int y = 0; y < size; y++)
	{

		for (int x = 0; x < size; x++)
		{

			gameboard[x][y]->setVis(unknownLit);
			switch (map->getTile(x, y))
			{
			case MapGen::Unused:
				gameboard[x][y]->setTile(Unused);
				gameboard[x][y]->setColor(.6, .6, .6);
				break;
			case MapGen::Floor:
				gameboard[x][y]->setTile(Floor);
				gameboard[x][y]->setColor(0.6, 0.6, 0.6);
				break;
			case MapGen::Corridor:
				gameboard[x][y]->setTile(Corridor);
				gameboard[x][y]->setColor(0.75, 0.75, 0.75);
				break;
			case MapGen::Wall:
				gameboard[x][y]->setTile(Wall);
				gameboard[x][y]->setColor(0.75, 0.75, 0.75);
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

				if (canMove(x - 1, y))
				{
					player = new Player(x - 1, y); // spawns player left of upstairs
					gameboard[x - 1][y]->setEntityType(entityType::player);

					doFov(x, y, 2, lightlevel_3);
				}
				else if (canMove(x, y - 1))
				{
					player = new Player(x, y - 1); // spawns player right of upstairs
					gameboard[x - 1][y]->setEntityType(entityType::player);

					doFov(x, y, 2, lightlevel_3);
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
	}


	upToDate = true;
	stepCounter = 0;
	//inProgress = false;

}

void Board::draw()
{

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{

			gameboard[i][j]->draw();
		}
	}
	catchUp();
}

void Board::handle(unsigned char key)
{
	int playerX = player->getX();
	int playerY = player->getY();

	if (key == 'w')
	{
		if (canMove(playerX, playerY - 1, true))
		{
			//std::cout << "moving up " << std::endl;
			player->moveUp();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			lightPlayer(player->getX(), player->getY());
			behind();
			stepCounter++;
			spawnHandler();
		}
		stepCounter++;
		monsterHandler();
		behind();
	}
	if (key == 'a')
	{
		if (canMove(playerX - 1, playerY, true))
		{
			//std::cout << "moving left" << std::endl;
			player->moveLeft();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			lightPlayer(player->getX(), player->getY());
			behind();
			stepCounter++;
			spawnHandler();
		}
		stepCounter++;
		monsterHandler();
		behind();
	}
	if (key == 'd')
	{
		if (canMove(playerX + 1, playerY, true))
		{
			//std::cout << "moving right" << std::endl;
			player->moveRight();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			lightPlayer(player->getX(), player->getY());
			behind();
			stepCounter++;
			spawnHandler();
		}
		stepCounter++;
		monsterHandler();
		behind();
	}
	if (key == 's')
	{
		if (canMove(playerX, playerY + 1, true))
		{
			//std::cout << "moving down " << std::endl;
			player->moveDown();
			gameboard[playerX][playerY]->setEntityType(entityType::empty);
			gameboard[player->getX()][player->getY()]->setEntityType(entityType::player);
			lightPlayer(player->getX(), player->getY());
			behind();
			stepCounter++;
			spawnHandler();
		}
		stepCounter++;
		monsterHandler();
		behind();
	}
	if (key == 'e') {
		// pick up



	}
	if (key == 'f') {
		// search



	}


}

void Board::check()
{

}



void Board::reset()
{
	stepCounter = 0;
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

void Board::behind()
{
	upToDate = false;
}

void Board::setVisited(uint x, uint y, bool visited)
{
	gameboard[x][y]->_visited(visited);
}

void Board::setVisible(uint x, uint y, visibility vis)
{

	gameboard[x][y]->setVis(vis);
}

bool Board::isOpaque(uint x, uint y) const
{
	tileType checktile = gameboard[x][y]->getTile();
	if (checktile == Wall || checktile == ClosedDoor)
	{
		return true;
	}
	return false;
}

void Board::lightPlayer(int x, int y)
{
	if (stepCounter > 2) {
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (gameboard[i][j]->getVisited() == true)
				{
					gameboard[i][j]->setVis(recentlyLit);
				}
			}
		}
	}

	doFov(x, y);
	doFov(x, y, 3, lightLevel_2);
	doFov(x, y, 2, lightLevel_1);
}

void Board::castLight(uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy, visibility visState)
{
	if (start_slope < end_slope)
	{
		return;
	}
	float next_start_slope = start_slope;
	for (uint i = row; i <= radius; i++)
	{
		bool blocked = false;
		for (int dx = -i, dy = -i; dx <= 0; dx++)
		{
			float l_slope = (dx - 0.5) / (dy + 0.5);
			float r_slope = (dx + 0.5) / (dy - 0.5);
			if (start_slope < r_slope)
			{
				continue;
			}

			else if (end_slope > l_slope)
			{
				break;
			}

			int sax = dx * xx + dy * xy;
			int say = dx * yx + dy * yy;
			if ((sax < 0 && (uint)std::abs(sax) > x) ||
				(say < 0 && (uint)std::abs(say) > y))
			{
				continue;
			}
			uint ax = x + sax;
			uint ay = y + say;
			if (ax >= 49 || ay >= 49)
			{
				continue;
			}

			uint radius2 = radius * radius;
			if ((uint)(dx * dx + dy * dy) < radius2)
			{
				setVisible(ax, ay, visState);
				setVisited(ax, ay, true);
			}

			if (blocked)
			{
				if (isOpaque(ax, ay))
				{
					next_start_slope = r_slope;
					continue;
				}
				else
				{
					blocked = false;
					start_slope = next_start_slope;
				}
			}
			else if (isOpaque(ax, ay))
			{
				blocked = true;
				next_start_slope = r_slope;
				castLight(x, y, radius, i + 1, start_slope, l_slope, xx,
					xy, yx, yy, visState);
			}
		}
		if (blocked)
		{
			break;
		}
	}
}
void Board::monsterView(uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy,int m)
{
	if (start_slope < end_slope)
	{
		return;
	}
	float next_start_slope = start_slope;
	for (uint i = row; i <= radius; i++)
	{
		bool blocked = false;
		for (int dx = -i, dy = -i; dx <= 0; dx++)
		{
			float l_slope = (dx - 0.5) / (dy + 0.5);
			float r_slope = (dx + 0.5) / (dy - 0.5);
			if (start_slope < r_slope)
			{
				continue;
			}

			else if (end_slope > l_slope)
			{
				break;
			}

			int sax = dx * xx + dy * xy;
			int say = dx * yx + dy * yy;
			if ((sax < 0 && (uint)std::abs(sax) > x) ||
				(say < 0 && (uint)std::abs(say) > y))
			{
				continue;
			}
			uint ax = x + sax;
			uint ay = y + say;
			if (ax >= 49 || ay >= 49)
			{
				continue;
			}

			uint radius2 = radius * radius;
			if ((uint)(dx * dx + dy * dy) < radius2)
			{
				if (ax == player->getX() && ay == player->getY()) {
					monsterList[m]->awaken();
				}
			}

			if (blocked)
			{
				if (isOpaque(ax, ay))
				{
					next_start_slope = r_slope;
					continue;
				}
				else
				{
					blocked = false;
					start_slope = next_start_slope;
				}
			}
			else if (isOpaque(ax, ay))
			{
				blocked = true;
				next_start_slope = r_slope;
				monsterView(x, y, radius, i + 1, start_slope, l_slope, xx,
						  xy, yx, yy, m);
			}
		}
		if (blocked)
		{
			break;
		}
	}
}

void Board::doFov(uint x, uint y, uint radius, visibility vis)
{
	for (uint i = 0; i < 8; i++)
	{
		castLight(x, y, radius, 1, 1.0, 0.0, multipliers[0][i],
			multipliers[1][i], multipliers[2][i], multipliers[3][i], vis);
	}
}

//This starts the combat functions within the game.
void Board::doFov(uint x, uint y)
{
	uint radius = 6;

	for (uint i = 0; i < 8; i++)
	{
		visibility vis = lightlevel_3;
		castLight(x, y, radius, 1, 1.0, 0.0, multipliers[0][i],
				  multipliers[1][i], multipliers[2][i], multipliers[3][i], vis);
	}
}


void Board::doMonsterFov(uint x,uint y,int m){
	uint radius = 3;
	for (uint i = 0; i < 8; i++)
	{
		monsterView(x, y, radius, 1, 1.0, 0.0, multipliers[0][i],
				  multipliers[1][i], multipliers[2][i], multipliers[3][i],m);
	}
}



void Board::debug() {
	std::cout << "AC " << player->getAC() << std::endl;
	std::cout << "HP " << player->getHp() << std::endl;
	std::cout << "Init Bonus " << player->getInitBonus() << std::endl;
	std::cout << "Num Attacks " << player->getNumAttacks() << std::endl;
	std::cout << "STR " << player->getStre() << std::endl;
	std::cout << "DEX " << player->getDex() << std::endl;
	std::cout << "CON " << player->getCon() << std::endl;
	std::cout << "WIS " << player->getWis() << std::endl;
	std::cout << "INT " << player->getIntel() << std::endl;
	std::cout << "CHAR " << player->getChari() << std::endl;

}

void Board::monsterDebug(int m)
{

	int hp = monsterList[m]->getHp();
	std::cout << m << " with "<< hp <<" at " << monsterList[m]->getX() << " " << monsterList[m]->getY() << std::endl;
	if (hp < 0)
	{
		std::cout << "monster is dead " << std::endl;
	}
	else
	{
		std::cout << "monster is alive " << std::endl;
	}
}


void Board::combat(int m, bool attacking) {
	debug();
	int numPlayerAttacks = player->getNumAttacks();
	int numMonsterAttacks = monsterList[m]->getAttacks();
	//int playerinit = random->randomInt(20) + player->getInitBonus();
	//int monsterinit = random->randomInt(20) + monsterList[m]->getInitiativeBonus();

	if (attacking) {

		//std::cout << playerinit << " vs " << monsterinit << std::endl;

		while (numPlayerAttacks > 0)
		{
			if (monsterList[m]->getHp() > 0) {
				int playerAttack = player->rollToHit();
				int monsterAC = monsterList[m]->getAc();

				if (playerAttack >= monsterAC)
				{
					int damage = player->rollAttackDamage();
					std::cout << "You do " << damage << " to " << monsterList[m]->getName() << std::endl;
					monsterList[m]->setHp(monsterList[m]->getHp() - damage);

				}
			}
			if (monsterList[m]->getHp() < 0) {

				std::cout << "You KILL the " << monsterList[m]->getName() << std::endl;
				player->grantExp(monsterList[m]->getExp());
				player->levelHandler();

				break;

			}
			numPlayerAttacks--;
		}

		monsterDebug(m);
		for (int i = 0; i < numMonsterAttacks; i++)
		{
			if (monsterList[m]->getHp() < 0) {
				break;
			}
			std::cout << "player hp " << player->getHp() << std::endl;
			if (player->getHp() > 0) {
				if (monsterList[m]->rollToHIt() >= player->getAC()) {
					//player->takesDamage(monsterList[m]->rollDamage());
					//player->takesDamage(random->rollDie(1, monsterList[m]->getWeaponType()));
				}
			}
			else {
				// player dies @todo
				std::cout << "You DIE" << std::endl;
			}
		}

		monsterDebug(m);




		if (monsterList[m]->getHp() <= 0)
		{
			std::cout << "Deleting Monster "  << m << std::endl;
			std::cout << monsterList[m]->getX() << std::endl;
			std::cout << monsterList[m]->getY() << std::endl;
			int x = monsterList[m]->getX();
			int y = monsterList[m]->getY();
			delete monsterList[m];
			monsterList.erase(monsterList.begin() + m);
			gameboard[x][y]->setEntityType(empty);
		}
	}
	else
	{

		for (int i = 0; i < numMonsterAttacks; i++)
		{
			if (monsterList[m]->getHp() < 0) {
				break;
			}
			std::cout << "attacking Player " << player->getHp() << std::endl;
			if (player->getHp() > 0) {
				if (monsterList[m]->rollToHIt() >= player->getAC()) {
					//player->takesDamage(monsterList[m]->rollDamage());
					//player->takesDamage(random->rollDie(1, monsterList[m]->getWeaponType()));
				}
			}
			else {
				// player dies @todo
				std::cout << "You DIE" << std::endl;
			}
		}
	}
	for (int i = 0; i < monsterList.size(); i++)
	{
		std::cout << i << " " << monsterList[i]->getX() << " " << monsterList[i]->getY() << std::endl;
	}
}

int Board::monsterAt(int x, int y)
{
	for (int i = 0; i < monsterList.size(); i++)
	{
		if (monsterList[i]->getX() == x && monsterList[i]->getY() == y)
		{
			return i;
		}
	}
}

void Board::spawnMonster(int tries, int num)
{
	int numMonsters = 0;
	std::cout << "spawned monster called " << std::endl;
	int rX, rY; // random x random y

	for (int i = 0; i < tries; i++)
	{
		if (numMonsters > num - 1)
		{
			break;
		}

		rX = random->randomInt(49);
		rY = random->randomInt(49);

		if (canMove(rX, rY) && !currentlyViewed(rX, rY) && gameboard[rX][rY]->getTile() == Unused)
		{
			std::cout << rX << " " << rY << std::endl;
			monsterList.push_back(new Goblin(rX, rY)); //only one monster, plan to spawn different ones;

			gameboard[rX][rY]->setEntityType(monster);

			std::cout << "spawned monster " << numMonsters <<  " at " << monsterList[monsterAt(rX,rY)]->getX() << " " << monsterList[monsterAt(rX, rY)]->getY() <<  std::endl;
			numMonsters++;
		}

	}

}

void Board::itemSpawner(int tries, int num)
{
	int numItems = 0;
	int rX, rY; // random x random y

	for (int i = 0; i < tries; i++)
	{
		if (numItems > num - 1)
		{
			break;
		}

		rX = random->randomInt(49);
		rY = random->randomInt(49);

		if (canMove(rX, rY) && !currentlyViewed(rX, rY) && gameboard[rX][rY]->getTile() == Unused && gameboard[rX][rY]->getLootable() == _Empty)
		{
			switch (random->randomInt(3))
			{
			case 1:
				loot->spawnItem(weapon_, rX, rY);
			default:
				break;
			}
			
			numItems++;
		}

	}

}

void Board::spawnHandler()
{
	if (stepCounter == 1)
	{
		spawnMonster(1000, 10);
		itemSpawner(100, 5);
	}
	if (stepCounter % 100 == random->randomInt(100) && monsterList.size() <= 30) { // something to randomly spawn monster
		spawnMonster(30, 1);
	}

	if (stepCounter % 100 == random->randomInt(30) && loot->getNumItems() <= 15) { // something to randomly spawn items
		itemSpawner(30, 1);
	}

}

bool Board::currentlyViewed(int x, int y)
{
	switch (gameboard[x][y]->getVis())
	{
	case lightLevel_1:
		return true;
	case lightLevel_2:
		return true;
		break;
	case lightlevel_3:
		return true;
		break;
	default:
		return false;
		break;
	}
}



void Board::catchUp()
{
	upToDate = true;
}

bool Board::isUpToDate() const
{
	return upToDate;
}

bool Board::canMove(int endX, int endY)
{
	if (gameboard[endX][endY]->getTile() == Wall || gameboard[endX][endY]->getTile() == ClosedDoor || gameboard[endX][endY]->getEntityType() == monster || gameboard[endX][endY]->getTile() == Floor || gameboard[endX][endY]->getEntityType() == entityType::player)
	{
		if (gameboard[endX][endY]->getTile() == Floor || gameboard[endX][endY]->getTile() == Corridor)
		{
			return true;
		}
		return false;
	}
	else
		return true;
}

bool Board::canMove(int endX, int endY, bool player,int m)
{
	if (gameboard[endX][endY]->getTile() == Wall || gameboard[endX][endY]->getTile() == ClosedDoor || gameboard[endX][endY]->getEntityType() == monster || gameboard[endX][endY]->getEntityType() == entityType::player )
	{
		if (gameboard[endX][endY]->getEntityType() == monster && player == true) {
			std::cout << "Starting Combat" << std::endl;
			int attackedMonster = monsterAt(endX, endY);
			combat(attackedMonster, true);

			stepCounter++;
			behind();
			//check();
		}
		else if (gameboard[endX][endY]->getEntityType() == entityType::player && player == false){
			combat(m, false);
		}

		return false;
	}
	else
		return true;
}


void Board::MonsterAi(int m){
	//std::cout << "Monster " << m << " " << monsterList[m]->isAwake()  << " "<< monsterList[m]->getX() << " " << monsterList[m]->getY() << '\n';
	if (monsterList[m]->isAwake()){
		//do shit
		//std::cout << "Monster " << m << " is awake " << monsterList[m]->getX() << " " << monsterList[m]->getY() << '\n';
		int monsterX = monsterList[m]->getX();
		int monsterY = monsterList[m]->getY();
		int playerX = player->getX();
		int playerY = player->getY();
		 
		if (monsterX < playerX && monsterY > playerY) {
			if (canMove(monsterList[m]->getX() + 1, monsterList[m]->getY() - 1)) {
				monsterMoveHandler(m, upRight);
			}
		}
		else if (monsterX > playerX && monsterY > playerY) {
			monsterMoveHandler(m, upLeft);
		}
		else if (monsterX < playerX && monsterY < playerY) {
			monsterMoveHandler(m, downRight);
		}
		else if (monsterX > playerX && monsterY < playerY) {
			monsterMoveHandler(m, downLeft);
		}
		else if (monsterX == playerX && monsterY > playerY) {
			monsterMoveHandler(m, up);
		}
		else if (monsterX == playerX && monsterY < playerY) {
			monsterMoveHandler(m, down);
		}
		else if (monsterX < playerX && monsterY == playerY) {
			monsterMoveHandler(m, right);
		}
		else if (monsterX > playerX && monsterY == playerY) {
			monsterMoveHandler(m, left);
		}
		
	}
	else if(stepCounter > 4 && !monsterList[m]->isAwake()){
		//std::cout << "Monster " << m << " is not awake " << monsterList[m]->getX() << " " << monsterList[m]->getY() << '\n';
		MonsterIdle(m); // randomly walk around untill it sees the player
		doMonsterFov(monsterList[m]->getX(),monsterList[m]->getY(),m);
	}
}

void Board::MonsterIdle(int m,int t){
	
	int tries = t;
	if (!monsterMoveHandler(m, (direction)random->randomInt(numDirections)) && tries < 5) {
		tries++;
		MonsterIdle(m,tries);
	}

	

}

void Board::monsterHandler(){
	for (int i = 0; i < monsterList.size(); i++) {
		MonsterAi(i);
	}
}

bool Board::monsterMoveHandler(int m, direction going,int tries) {
	int monsterX = monsterList[m]->getX();
	int monsterY = monsterList[m]->getY();
	if (tries > 3)
	{
		return true;
	}

	switch (going) {
	case upLeft:
		if (canMove(monsterList[m]->getX() - 1, monsterList[m]->getY() - 1,false,m)) {
			monsterList[m]->moveUpLeft();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		if (random->randomBool())
		{
			tries++;
			if (monsterMoveHandler(m, up,tries))
				return true;
			else if (monsterMoveHandler(m, left,tries))
			{
				return true;
			}
		}
		else {
			tries++;
			if (monsterMoveHandler(m, left,tries))
			{
				return true;
			}
			else if (monsterMoveHandler(m, up,tries))
			return true;
		}
		
		
		
		break;
	case up:
		if (canMove(monsterList[m]->getX(), monsterList[m]->getY() - 1, false, m)) {
			monsterList[m]->moveUp();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		tries++;
		break;
	case upRight:
		if (canMove(monsterList[m]->getX() + 1, monsterList[m]->getY() - 1, false, m)) {
			monsterList[m]->moveUpRight();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		else {
			if (random->randomBool())
			{
				tries++;
				if (monsterMoveHandler(m, up,tries))  return true;
				else if (monsterMoveHandler(m, right, tries)) return true;
			}
			else
			{
				tries++;
				if (monsterMoveHandler(m, right, tries))  return true;
				else if (monsterMoveHandler(m, up,tries)) return true;
			}
			
		}
		
		break;

	case left:
		if (canMove(monsterList[m]->getX() - 1, monsterList[m]->getY(), false, m)) {
			monsterList[m]->moveLeft();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		tries++;
		break;
	case right:
		if (canMove(monsterList[m]->getX() + 1, monsterList[m]->getY(), false, m)) {
			monsterList[m]->moveRight();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		tries++;
		break;

	case downLeft:

		if (canMove(monsterList[m]->getX() - 1, monsterList[m]->getY() + 1, false, m)) {
			monsterList[m]->moveDownLeft();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		else {
			if (random->randomBool())
			{
				tries++;
				if (monsterMoveHandler(m, down,tries))  return true;
				else if (monsterMoveHandler(m, left,tries)) return true;
			}
			else
			{
				tries++;
				if (monsterMoveHandler(m, left,tries))  return true;
				else if (monsterMoveHandler(m, down,tries)) return true;
			}
		}

		break;
	case downRight:

		if (canMove(monsterList[m]->getX() + 1, monsterList[m]->getY() + 1, false, m)) {
			monsterList[m]->moveDownRight();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		else {
			if (random->randomBool())
			{
				tries++;
				if (monsterMoveHandler(m, down,tries))  return true;
				else if (monsterMoveHandler(m, right, tries)) return true;
			}
			else
			{
				tries++;
				if (monsterMoveHandler(m, right, tries))  return true;
				else if (monsterMoveHandler(m, down,tries)) return true;
			}
		}

		break;
	case down:

		if (canMove(monsterList[m]->getX(), monsterList[m]->getY() + 1, false, m)) {
			monsterList[m]->moveDown();
			gameboard[monsterX][monsterY]->setEntityType(entityType::empty);
			gameboard[monsterList[m]->getX()][monsterList[m]->getY()]->setEntityType(entityType::monster);
			return true;
		}
		tries++;
		break;
	default:
		break;
	}
	tries++;
	return false;
}
Board::~Board()
{
	delete loot;
	delete random;
	delete map;
	delete player;
	for (int i = 0; i < monsterList.size(); i++)	
	{
		delete monsterList[i];
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			delete gameboard[i][j];
		}
	}
}
