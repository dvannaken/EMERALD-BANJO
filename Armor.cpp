#include "Armor.h"

Armor::Armor():Item(0,0)
{
	ac = 10;
	bonusModifer = 0;
	strRequirement = 0;
}

Armor::Armor(int x, int y):Item(x,y)
{
	ac = 10;
	bonusModifer = 0;
	strRequirement = 0;
}

Armor::~Armor()
{

}

void Armor::setBonusModifier(int mod)
{
	this->bonusModifer = mod;
}

int Armor::getBonusModifer()
{
	return bonusModifer;

}

int Armor::getAc()
{
	return ac;
}

int Armor::getStrRequirement()
{
	return strRequirement;
}

ArmorType Armor::getArmorType()
{
	return type;
}

ArmorWeight Armor::getWeight()
{
	return weight;
}

std::string Armor::getName() {
	return name;
}