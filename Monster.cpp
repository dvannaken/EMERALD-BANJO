#include "Monster.h"

Monster::Monster():Entity(3,3) //constructor
{
}

Monster::~Monster()
{
	delete numGenerator;
}

Monster::Monster(int x, int y) :Entity(x,y)
{
}

Monster::Monster(const Monster & m2):Entity(m2.x,m2.y) {
	level = m2.level;
	ac = m2.ac;
	hp = m2.hp;
	toHit = m2.toHit;
	exp = m2.exp;
	attacks = m2.attacks;
	movementPerRound = m2.movementPerRound;
	detectionRadius = m2.detectionRadius;
	weaponSize = m2.weaponSize;
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

std::string Monster::getName() const
{
	return name;
}

int Monster::rollToHIt()
{
	numGenerator->randomInt(20) + toHit;

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

void Monster::setName(std::string name)
{
	this->name = name;
}
int Monster::rollDamage() {
	return numGenerator->rollDie(1, weaponSize);
}


