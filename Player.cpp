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
	init();
}

Player::~Player()
{
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
	int damage = dice->rollDie(1, 8) + streBonus;
	return damage;
}

void Player::calculateToHitBonus() {
	toHitBonus = profBonus + streBonus;
}

int Player::rollToHit()
{
	return dice->randomInt(20) + toHitBonus;
}

void Player::levelHandler()
{
	if (this->exp > expThreshold[level])
	{
		//player has leveled up;
		levelUp();
	}

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
	calculateBonus();
	calculateProfBonus();
	calculateToHitBonus();
	exp = 0;
	level = 1;
	hp = 8 + conBonus;
	hunger = Satiated;
	numAttacks = 1;
	expBoundries = level_1;
	initBonus = dexBonus + profBonus;

	expThreshold = {level_1, level_2,level_3,level_4,level_5,level_6,level_7,level_8,level_9,level_10};

}
void Player::levelUp()
{
	level++;
	hp += dice->rollDie(1, 8) + conBonus;
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
	return hp;
}

int Player::getInitBonus() const
{
	return initBonus;
}

int Player::getAC() const
{
	return ac;
}

//setters
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

void Player::grantExp(int exp)
{
	this->exp += exp;
}

void Player::takesDamage(int damage)
{
	hp -= damage;
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
