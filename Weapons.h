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
	BattleAxe();
	~BattleAxe();
	
};

class GreatAxe:public Weapons
{
public:
	GreatAxe()
	{
		this->damageDie = 12;
		this->oneHanded = false;
		this->name = "Great Axe";
	}

};
class Greatsword : public Weapons
{
public:
	Greatsword()
	{
		this->damageDie = 6;
		this->numOfDamageDie = 2;
		this->oneHanded = false;
		this->name = "Greatsword";
	}

};
class Longsword : public Weapons
{
public:
	Longsword()
	{
		this->damageDie = 8;
		this->numOfDamageDie = 1;
		this->oneHanded = false;
		this->name = "Longsword";
	}

};

class Warhammer : public Weapons
{
public:
	Warhammer()
	{
		this->damageDie = 8;
		this->numOfDamageDie = 1;
		this->oneHanded = true;
		this->name = "Warhammer";
	}

};
class Mjolnir : public Warhammer
{
public:
	Mjolnir()
	{
		this->damageDie = 12;
		this->numOfDamageDie = 2;
		this->oneHanded = true;
		this->name = "Mjolnir";
	}

};
class Excalibur : public Longsword
{
public:
	Excalibur()
	{
		this->damageDie = 6;
		this->numOfDamageDie = 3;
		this->oneHanded = true;
		this->name = "Excalibur";
	}

};
class Dagger : public Weapons
{
public:
	Dagger()
	{
		this->damageDie = 4;
		this->numOfDamageDie = 1;
		this->oneHanded = true;
		this->name = "Dagger";
	}

};





#endif // !Weapons_HPP
