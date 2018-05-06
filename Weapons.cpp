#include "Weapons.h"

Weapons::Weapons()
{
	this->damageDie = 4;
	this->numOfDamageDie = 1;
	this->bonusModifer = 0;
}

Weapons::Weapons(int x, int y):Item(x,y)
{
	this->damageDie = 4;
	this->numOfDamageDie = 1;
	this->bonusModifer = 0;
}

Weapons::~Weapons()
{
	delete dice;
}

Weapons::Weapons(const Weapons & w2)
{
	this->damageDie = w2.damageDie;
	this->numOfDamageDie = w2.numOfDamageDie;
	this->bonusModifer = w2.bonusModifer;
	this->name = w2.name;
}

int Weapons::getDamageDie() const
{
	return damageDie;
}

int Weapons::getNumDamageDie() const
{
	return numOfDamageDie;
}

int Weapons::getBonusModifer() const
{
	return bonusModifer;
}

std::string Weapons::getWeaponName() const
{
	return name;
}

int Weapons::calculateDamage()
{
	return dice->rollDie(numOfDamageDie, damageDie) + bonusModifer;
}
