#ifndef Armor_hpp
#define Armor_hpp
#include "Items.h"
#include <string>
enum ArmorType
{
	Head,
	Body,
	Arms,
	Fingers,
	Feet,
	shield,
	other

};
enum ArmorWeight
{
	Heavy,
	Medium,
	Light,
	Shield
};

class Armor: public Item
{
public:
	Armor();
	Armor(int, int); //spawns armor peice at location x,y
	~Armor();

	void setBonusModifier(int);
	
	int getBonusModifer();
	int getAc();
	int getStrRequirement();
	ArmorType getArmorType();
	ArmorWeight getWeight();
	std::string getName();

protected:
	int strRequirement;
	int ac;
	int bonusModifer;
	ArmorType type;
	ArmorWeight weight;
	std::string name;

};

class Leather: public Armor
{
public:
	Leather(int x = 0, int y = 0, int bonus = 0) : Armor(x, y)
	{
		this->ac = 11;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Light;
		this->name = "Leather Armor";
	}

};
class StuddedLeather : public Armor
{
public:
	StuddedLeather(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 12;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Light;
		this->name = "Studded Leather Armor";
	}

};

class Hide : public Armor
{
public:
	Hide(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 12;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Medium;
		this->name = "Hide Armor";
	}

};
class Chain_Shirt : public Armor
{
public:
	Chain_Shirt(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 13;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Medium;
		this->name = "Chain Shirt";

	}

};

class Scale_Mail : public Armor
{
public:
	Scale_Mail(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 14;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Medium;
		this->name = "Scale Mail";
	}

};
class Breastplate : public Armor
{
public:
	Breastplate(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 14;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Medium;
		this->name = "Brestplate";
	}

};
class Halfplate : public Armor
{
public:
	Halfplate(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 15;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Medium;
		this->name = "Halfplate";
	}

};
class Ring_Mail : public Armor
{
public:
	Ring_Mail(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 14;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Heavy;
		this->name = "Ring Mail";
	}

};
class Chain_Mail : public Armor
{
public:
	Chain_Mail(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 16;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Heavy;
		this->strRequirement = 13;
		this->name = "Chain Mail";
	}

};

class Splint : public Armor
{
public:
	Splint(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 17;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Heavy;
		this->strRequirement = 15;
		this->name = "Splint";
	}

};

class Plate : public Armor
{
public:
	Plate(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 18;
		this->bonusModifer = bonus;
		this->type = Body;
		this->weight = Heavy;
		this->strRequirement = 15;
		this->name = "Plate Mail";
	}

};

class WearableShield: public Armor
{
public:
	WearableShield(int x, int y, int bonus = 0) : Armor(x, y)
	{
		this->ac = 2;
		this->bonusModifer = bonus;
		this->type = ArmorType::shield;
		this->weight = ArmorWeight::Shield;
		this->name = "Shield";
	}

	~WearableShield(){

	}

private:

};








#endif // !Armor_hpp
