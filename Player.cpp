#include "Player.h"
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Player::Player() : Entity(25, 25)
{
	init();
}

Player::Player(int x, int y) : Entity(x, y)
{
	currentWeapon = new Longsword();
	currentArmor = new Leather();
	init();
}

Player::~Player()
{
	delete currentArmor;
	delete currentWeapon;
	delete dice;
}

int Player::generateStats()
{
	dice = new RandomNum();

	int* rolls;
	rolls = new int[4];
	int total = 0;

	for (int i = 0; i < 4; i++)
	{
		rolls[i] = dice->randomInt(6);
	}



	for (int i = 0; i < 4; i++)
	{
		total += rolls[i];
	}
	total - smallest(rolls);

	
	delete rolls;

	return total;
}

int Player::calculateProfBonus() {
	int bonus = 2;

	return bonus + (level / 4);
}

int Player::rollAttackDamage() {
	//based on weapons; @todo
	return currentWeapon->calculateDamage();
	
}

void Player::calculateToHitBonus() {
	toHitBonus = profBonus + streBonus;
}

int Player::rollToHit()
{
	return dice->randomInt(20) + toHitBonus;
}

bool Player::levelHandler()
{
	if (this->exp > expThreshold[level])
	{
		//player has leveled up;
		std::cout << "You have leveled Up" << std::endl;
		levelUp();
		return true;
	}
	return false;
}

void Player::recalculateAC()
{
	switch (currentArmor->getWeight())
	{
	case Heavy:
		ac = currentArmor->getAc() + currentArmor->getBonusModifer();
		break;
	case Medium:
		ac = currentArmor->getAc() + currentArmor->getBonusModifer() +  std::min(dexBonus, 2);
		break;
	case Light:
		ac = currentArmor->getAc() + currentArmor->getBonusModifer() + dexBonus;
		break;
	}
	if (usingShield)
	{
		ac += 2;
	}
}

void Player::switchArmor(Armor* pickedUpArmor)
{
	Armor* tempArmor = currentArmor;
	currentArmor = pickedUpArmor;
	delete tempArmor;
	recalculateAC();
}

void Player::switchWeapon(Weapons* pickedUpWeapon) {
	Weapons* tempWeap = currentWeapon;
	currentWeapon = pickedUpWeapon;
	delete tempWeap;
}

int Player::calculateBonus(int stat) // creates the bonus
{
	return((stat - 10) / 2);
	
}
void Player::calculateBonus() { // generates all the bonuses
	streBonus = calculateBonus(stre);
	dexBonus = calculateBonus(dex);
	conBonus = calculateBonus(con);
	intelBonus = calculateBonus(intel);
	wisBonus = calculateBonus(wis);
	chariBonus = calculateBonus(chari);
}
void Player::init()
{	
	do
	{
		setStre(generateStats());
		setDex(generateStats());
		setCon(generateStats());
		setWis(generateStats());
		setIntel(generateStats());
		setChari(generateStats());
		calculateBonus();
		calculateProfBonus();
		calculateToHitBonus();
	} while ((stre + dex + con + intel + wis + chari) < 65);
	name = "TEST";
	exp = 0;
	level = 1;
	maxHP = 8 + conBonus;
	currentHP = maxHP;
	hunger = Satiated;
	numAttacks = 1;
	expBoundries = level_1;
	initBonus = dexBonus + profBonus;

	expThreshold = {level_1, level_2,level_3,level_4,level_5,level_6,level_7,level_8,level_9,level_10};
	recalculateAC();

}
void Player::levelUp()
{
	level++;
	int inc = dice->rollDie(1, 8) + conBonus;
	maxHP += inc;
	currentHP += inc; 
	calculateBonus();
	calculateProfBonus();
	calculateToHitBonus();


}
int Player::smallest(int* rolls) {
	int small = 7;
	for (int i = 0; i < 4; i++)
	{
		if (rolls[i] < small) {
			small = rolls[i];
		}
	}
	return small;
}

//getters
int Player::getCon() const {
	return con;
}

int Player::getChari() const {
	return chari;
}

int Player::getWis() const {
	return wis;
}

int Player::getDex() const {
	return dex;
}

int Player::getIntel() const {
	return intel;
}

int Player::getStre() const {
	return stre;
}

int Player::getNumAttacks() const
{
	return numAttacks;
}

int Player::getHp() const
{
	return currentHP;
}

int Player::getMaxHp() const
{
	return maxHP;
}

int Player::getExp() const
{
	int currentExp = exp - expThreshold[level-1]; //experience for current level
	return currentExp;
}

int Player::getMaxExp() const
{
	int currentMax = expThreshold[level] - expThreshold[level-1]; //experience quota for current level
	return currentMax;
}

std::string Player::getName() const
{
	return name;
}

int Player::getLevel() const
{
	return level;
}

int Player::getInitBonus() const
{
	return initBonus;
}

int Player::getAC() const
{
	return ac;
}

bool Player::isUsingShield() const
{
	return usingShield;
}

std::string Player::getCurrentWeaponName()
{
	return currentWeapon->getWeaponName();
}

int Player::getCurrentWeaponBonusModifer()
{
	return currentWeapon->getBonusModifer();
}

std::string Player::getCurrentArmorName()
{
	return currentArmor->getName();
}

int Player::getCurrentArmorBonusModifer()
{
	return currentArmor->getBonusModifer();
}


//setters
void Player::setName(std::string name) {
	this->name = name;
}

void Player::setCon(int con) {
	this->con = con;
}

void Player::setChari(int chari) {
	this->chari = chari;
}

void Player::setWis(int wis) {
	this->wis = wis;
}

void Player::setDex(int dex) {
	this->dex = dex;
}

void Player::setIntel(int intel) {
	this->intel = intel;
}

void Player::setStre(int stre) {
	this->stre = stre;
}

void Player::setNumAttacks(int attacks)
{
	this->numAttacks = attacks;
}

void Player::setInitBonus(int bonus)
{
	
}

void Player::setUsingShield(bool shield)
{
	this->usingShield = shield;
}

void Player::grantExp(int exp)
{
	this->exp += exp;
}

void Player::takesDamage(int damage)
{
	currentHP -= damage;

	if (currentHP < 0)
		currentHP = 0;
}

void Player::heals(int health)
{
	currentHP += health;
	
	if (currentHP > maxHP)
		currentHP = maxHP;
}

//we're gonna use 2d array, so like 2 for loops???
void Player::moveUp() {
	y -= 1;
}

void Player::moveDown() {
	y += 1;
}

void Player::moveLeft() {
	x -=1 ;
}

void Player::moveRight() {
	x +=1 ;
}
