#include "Monster.h"

Monster::Monster():Entity(3,3) //constructor
{
	numGenerator = new RandomNum();
}

Monster::~Monster()
{
	delete numGenerator;
}

Monster::Monster(int, int) :Entity(x,y)
{
	numGenerator = new RandomNum();
}


void Monster::moveUp()
{
	y -= 1;
}

void Monster::moveDown()
{
	y += 1;
}

void Monster::moveLeft()
{
	x -= 1;
}

void Monster::moveRight()
{
	x += 1;
}

void Monster::moveUpLeft()
{
	moveUp();
	moveLeft();

}

void Monster::moveUpRight()
{
	moveUp();
	moveRight();

}

void Monster::moveDownLeft()
{
	moveDown();
	moveLeft();
}

void Monster::moveDownRight()
{
	moveDown();
	moveRight();
}



int Monster::getLevel() const
{
	return level;
}

int Monster::getAc() const
{
	return ac;
}

int Monster::getHp() const
{
	return hp;
}

int Monster::getToHit() const
{
	return toHit;
}

int Monster::getExp() const
{
	return exp;
}

int Monster::getAttacks() const
{
	return attacks;
}

int Monster::getMovementPerRound() const
{
	return movementPerRound;
}

int Monster::getWeaponType() const
{
	return weaponType();
}

int Monster::getInitiativeBonus() const
{
	return initiativeBonus;
}

int Monster::rollToHIt()
{
	numGenerator->randomInt(20) + toHit;
    return 0;

}

void Monster::setLevel(int level)
{
	this->level = level;
}

void Monster::setAc(int armorClass)
{
	ac = armorClass;
}

void Monster::setHp(int hp)
{
	this->hp = hp;
}

void Monster::setToHit(int hitbonus)
{
	this->toHit = hitbonus;
}

void Monster::setExp(int exp)
{
	this->exp = exp;
}

void Monster::setAttacks(int numAttacks)
{
	this->attacks = numAttacks;
}

void Monster::setMovementPerRound(int movement) 
{
	this->movementPerRound = movement;
}

void Monster::setMonsterType(weaponType size )
{
	weaponSize = size;
}

void Monster::setInitiativeBonus(int bonus)
{
	this->initiativeBonus = bonus;
}


