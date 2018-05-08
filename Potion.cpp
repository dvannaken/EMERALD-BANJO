#include "Potion.h"

Potion::Potion()
{
	this->bonusModifer = 0;
}

Potion::Potion(int x, int y):Item(x,y)
{
	this->bonusModifer = 0;
}

Potion::~Potion()
{
	delete dice;
}

void Potion::setBonusModifer(int x)
{
	this->bonusModifer = x;
}


int Potion::getBonusModifer() {
	return bonusModifer;
}

int Potion::getStatModifer() {
	return statModifer;
}

std::string Potion::getName()
{
	return name;
}
