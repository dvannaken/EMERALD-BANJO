#ifndef Weapons_HPP
#define Weapons_HPP
#include "Items.h"
#include <string>
#include "RandomNum.h"




class Weapons: public Item
{
public:
	Weapons();
	Weapons(int, int);
	~Weapons();

	Weapons(const Weapons&);

	int getDamageDie() const; // the sides of the dice thats rolled for damage
	int getNumDamageDie() const; // number of dice rolled
	int getBonusModifer() const; // bonus modifer that gets added on top.
	std::string getWeaponName() const;
	int calculateDamage();
	bool isOneHanded();
	void setBonusModifier(int);
	void switchDamage();

protected:
	int damageDie;
	int numOfDamageDie;
	int bonusModifer;
	bool oneHanded; 
	std::string name;
	RandomNum* dice = new RandomNum();
};

/// List of differnt Weapons


class BattleAxe: public Weapons
{
public:
	BattleAxe(int x, int y, int bonus = 0);
	~BattleAxe();
	
};

class GreatAxe:public Weapons
{
public:
	GreatAxe(int x, int y, int bonus = 0) :Weapons(x, y)
	{
		this->damageDie = 12;
		this->oneHanded = false;
		this->name = "Great Axe";
		this->bonusModifer = bonus;
	}

};
class Greatsword : public Weapons
{
public:
	Greatsword(int x, int y,int bonus = 0 ) :Weapons(x, y)
	{
		this->damageDie = 6;
		this->numOfDamageDie = 2;
		this->oneHanded = false;
		this->name = "Greatsword";
		this->bonusModifer = bonus;
	}

};
class Longsword : public Weapons
{
public:
	Longsword(int x = 0, int y = 0, int bonus = 0 ) : Weapons(x, y)
	{
		this->damageDie = 8;
		this->numOfDamageDie = 1;
		this->oneHanded = false;
		this->name = "Longsword";
		this->bonusModifer = bonus;
	}

};

class Warhammer : public Weapons
{
public:
	Warhammer(int x = 0, int y = 0, int bonus = 0 ) :Weapons(x, y)
	{
		this->damageDie = 8;
		this->numOfDamageDie = 1;
		this->oneHanded = true;
		this->name = "Warhammer";
		this->bonusModifer = bonus;
	}

};
class Mjolnir : public Warhammer
{
public:
	Mjolnir(int x, int y, int bonus = 0 ) : Warhammer(x, y)
	{
		this->damageDie = 12;
		this->numOfDamageDie = 2;
		this->oneHanded = true;
		this->name = "Mjolnir";
		this->bonusModifer = bonus;
	}

};
class Excalibur : public Longsword
{
public:
	Excalibur(int x, int y, int bonus = 0 ) :Longsword(x, y)
	{
		this->damageDie = 6;
		this->numOfDamageDie = 3;
		this->oneHanded = true;
		this->name = "Excalibur";
		this->bonusModifer = bonus;
	}

};
class Dagger : public Weapons
{
public:
	Dagger(int x, int y, int bonus = 0 ) :Weapons(x, y)
	{
		this->damageDie = 4;
		this->numOfDamageDie = 1;
		this->oneHanded = true;
		this->name = "Dagger";
		this->bonusModifer = bonus;
	}

};





#endif // !Weapons_HPP
