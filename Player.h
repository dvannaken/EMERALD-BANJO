#include "Entity.h"
#include "RandomNum.h"
#ifndef Player_h
#define Player_h

class Player : public Entity { //must have health element
private:
	enum HungerState
	{
		Oversatiated,
		Satiated,
		NotHungry,
		Peckish,
		Hungry,
		Weak,
		fainting,
		Starved

	};
	RandomNum * dice;

	int con; //this is the constitution/health
	int chari; //charisma
	int wis; //wisdom/perception
	int dex; //Dexterity
	int intel; //Intelligence
	int stre; //Strength

	int conBonus;
	int chariBonus;
	int wisBonus;
	int dexBonus;
	int intelBonus;
	int streBonus;
	int profBonus;

	int exp;
	int level;
	int ac; // armorclass needs to roll higher to hit
	int hp;
	HungerState hunger;
	int numAttacks;

	int toHitBonus; 

	int smallest(int*); // smallest number of a array;

	int calculateProfBonus();
	int generateStats();
	int calculateBonus(int);
	void calculateBonus();
	
	
	void calculateToHitBonus();
	

	void init();
	void levelUp(); // levels up character.
	

public:

	Player();
	Player(int, int);
	~Player();

	int getCon() const;
	int getChari() const;
	int getWis() const;
	int getDex() const;
	int getIntel() const;
	int getStre() const;
	int getNumAttacks() const;
	int getHp() const;

	void setCon(int);
	void setChari(int);
	void setWis(int);
	void setDex(int);
	void setIntel(int);
	void setStre(int);
	void setNumAttacks(int);

	//(virtual) add functions for movement: up, down, left and right
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();

	int rollAttackDamage();
	int rollToHit();
};



#endif
