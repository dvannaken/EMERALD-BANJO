#ifndef Weapons_HPP
#define Weapons_HPP
#include "Items.h"
#include <string>
#include "RandomNum.h"
class Weapons: public Item
{
public:
	Weapons();
	Weapons(int, int);
	~Weapons();

	Weapons(const Weapons&);

	int getDamageDie() const; // the sides of the dice thats rolled for damage
	int getNumDamageDie() const; // number of dice rolled
	int getBonusModifer() const; // bonus modifer that gets added on top.
	std::string getWeaponName() const;

	int calculateDamage();
private:
	int damageDie;
	int numOfDamageDie;
	int bonusModifer;
	std::string name;
	RandomNum* dice = new RandomNum();
};




#endif // !Weapons_HPP
