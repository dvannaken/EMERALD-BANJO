#ifndef Monster_HPP
#define Monster_HPP
#include "Entity.h"
#include "RandomNum.h"
#include <string>

class Monster: public Entity
{


enum drops
    {
        gold,
        armor,
        weapon
    };

    //Monster movement, to be used in movement Algorithm
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUpLeft();
    virtual void moveUpRight();
    virtual void moveDownLeft();
    virtual void moveDownRight();

    

public:
	enum weaponType // three basic times of enemy  for damage
	{
		giant = 12,
		large = 8,
		medium = 6,
		small = 4
	};

    Monster(); // constructor
    Monster(Monster &&) = default; 
    Monster(const Monster &) = default;
    Monster &operator=(Monster &&) = default;
    Monster &operator=(const Monster &) = default;
    ~Monster();

    Monster(int,int); // constructor with spawning location

    // getters or setters
    
    int getLevel() const; // gets the level of the monster
    int getAc() const;  // gets Armor class of monster
    int getHp() const; // gets hp of the monster
    int getToHit() const; // gets hitBonus for monster;
    int getExp() const; // exp given by monster when killed
    int getAttacks() const; //  how many attacks per attack attack zone. 
    int getMovementPerRound() const;
	weaponType getWeaponType() const;
    

   
    void setLevel(int);
    void setAc(int);
    void setHp(int);
    void setToHit(int);
    void setExp(int);
    void setAttacks(int);
    void setMovementPerRound(int);
	void setMonsterType(weaponType);

	RandomNum* numGenerator;
    
    


protected:

    int level; // monsters level, Higher level -> stronger monsters;
    int ac; // armor class, used to see what hits it or not.
    int hp; // health based on monster size and level
    int toHit; // bonuses when hiting              
    int exp;
    int attacks;
    int movementPerRound;
    int detectionRadius; 
	std::string attackMessage;
    weaponType weaponSize;



    
};


#endif // Monster

//more monsters should extend from this. 


