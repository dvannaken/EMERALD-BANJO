#ifndef Monster_HPP
#define Monster_HPP
#include "Entity.h"
#include "RandomNum.h"

class Monster: public Entity
{
enum classType // three basic times of enemy  for damage
    {
        giant = 12,  
        heavy = 8,
        medium = 6,
        light =  4

    };
enum drops
    {
        gold,
        armor,
        weapon
    };

public:
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
    classType getMonsterType() const;

   
    void setLevel(int);
    void setAc(int);
    void setHp(int);
    void setToHit(int);
    void setExp(int);
    void setAttacks(int);
    
    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUpLeft();
    virtual void moveUpRight();
    virtual void moveDownLeft();
    virtual void moveDownRight();



protected:

    int level;
    int ac;
    int hp;
    int toHit;
    int exp;
    int attacks;

    classType monsterSize;


    
};


#endif // Monster