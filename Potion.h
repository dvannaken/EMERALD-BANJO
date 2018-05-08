#ifndef Potion_HPP
#define Potion_HPP
#include "Items.h"
#include "RandomNum.h"
#include <string>
/*

Potions are magical drinks, some are very usefull, some are deadly.
Potions can be drunk if found, player can inspect a dropped potion and see what it is.

*/
enum Bonus
	{
		str,
		dex,
		con,
		wis,
		intel,
		chari,
		health,
		speed,
		level
	};
class Potion : public Item
{

	

	//enum adjatives {
	//	Ruby,
	//	Pink,
	//	Orange,
	//	Yellow,
	//	Emerald,
	//	Cyan,
	//	Puce,
	//	milky,
	//	swirly,
	//	bubbly,
	//	smoky,
	//	cloudy,
	//	effervesent,
	//	black,
	//	golden,
	//	brown,
	//	fizzy,
	//	dark,
	//	white,
	//	murky,
	//	numAdj
	//};

public:
	Potion();
	Potion(int, int); // spawns potion on x,y 
	~Potion();

	void setBonusModifer(int);

	int getBonusModifer();
	int getStatModifer();
	std::string getName();
protected:
	Bonus changing;
	//adjatives = nameModifer;
	RandomNum * dice = new RandomNum();
	std::string name;
	int bonusModifer;
	int statModifer;
};


class HealthPotion: public Potion
{
public:
	HealthPotion()
	{
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(2, 4) + 2;
	}

	HealthPotion(int x, int y) :Potion(x,y){

		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(2, 4) + 2;
	}

	~HealthPotion()
	{
	}

};

class GreaterHealthPotion : public Potion
{
public:
	GreaterHealthPotion()
	{
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(4, 4) + 4;
	}
	GreaterHealthPotion(int x, int y) :Potion(x, y) {
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(4, 4) + 4;
	}
	~GreaterHealthPotion()
	{
	}

};

class SuperiorHealthPotion : public Potion
{
public:
	SuperiorHealthPotion()
	{
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(8, 4) + 8;
	}
	SuperiorHealthPotion(int x, int y): Potion(x, y) {
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(8, 4) + 8;
	}
};

class SupremeHealthPotion :public  Potion
{
public:
	SupremeHealthPotion()
	{
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(10, 4) + 20;
	}
	SupremeHealthPotion(int x, int y) :Potion(x, y) {
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(10, 4) + 20;
	}
};

class Poison : public Potion
{
public:
	Poison()
	{
		this->bonusModifer = 0;
		this->changing = health;
		this->statModifer = dice->rollDie(1, 6) + 3;
	}
};









#endif // !Potion_HPP
