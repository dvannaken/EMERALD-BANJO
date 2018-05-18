#include "Entity.h"
#include "RandomNum.h"
#ifndef Player_h
#define Player_h
#include <vector>

#include "Weapons.h"
#include "Armor.h"

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

	enum levelThreshold {
		level_1 = 0,
		level_2 = 300,
		level_3 = 900,
		level_4 = 2700,
		level_5 = 6500,
		level_6 = 14000,
		level_7 = 28000,
		level_8 = 48000,
		level_9 = 64000,
		level_10 = 80000,
		levelMax = 10
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
	int initBonus;

	std::string name;
	int exp;
	int level;
	int ac; // armorclass needs to roll higher to hit
	int currentHP;
	int maxHP;

	HungerState hunger;
	levelThreshold expBoundries;
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

	std::vector<levelThreshold> expThreshold;
	
	// inventory 

	bool usingShield;
	Weapons* currentWeapon;
	Armor* currentArmor;
	




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
	int getMaxHp() const;
	int getExp() const;
	int getMaxExp() const;
	std::string getName() const;
	int getLevel() const;
	int getInitBonus() const;
	int getAC() const;
	bool isUsingShield() const;

	std::string getCurrentWeaponName();
	int getCurrentWeaponBonusModifer();

	std::string getCurrentArmorName();
	int getCurrentArmorBonusModifer();

	void setName(std::string);
	void setCon(int);
	void setChari(int);
	void setWis(int);
	void setDex(int);
	void setIntel(int);
	void setStre(int);
	void setNumAttacks(int);
	void setInitBonus(int);
	void setUsingShield(bool);

	void grantExp(int);
	void takesDamage(int);
	void heals(int);

	//(virtual) add functions for movement: up, down, left and right
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();

	int rollAttackDamage();
	int rollToHit();

	bool levelHandler();
	
	void recalculateAC();
	virtual void switchArmor(Armor*);
	virtual void switchWeapon(Weapons*);

};



#endif
