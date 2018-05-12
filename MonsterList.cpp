#include "MonsterList.h"


Goblin::Goblin(int x, int y): Monster(x,y)
{

	//This will be the basic templete for monsters, use this to add to the list;
	//Basing the monsters will be pulled from the DND MONSTER MANUAL, or some other reference guide.

	setLevel(1); // baisc goblin so level 1
	setAc(numGenerator->randomInt(7,10)); // Armor class randomizer
	setHp(numGenerator->rollDie(2,6) - 2); // Health randomizer
	setToHit(4); // the bonus to attack 
	setExp(50); // numberr of exp that is given on combat.
	setAttacks(1); // number of attacks per action
	setMovementPerRound(1); // 1 tiles per round, each round.
	setMonsterType(small); //for basic damage;
	setInitiativeBonus(2);
	setName("Goblin");
}
Goblin::~Goblin() {

}

GoblinLord::GoblinLord(int x, int y) :Monster(x, y)
{
	// a stronger goblin for later stages
	setLevel(4);
	setAc(numGenerator->randomInt(15, 17));
	setHp(numGenerator->rollDie(6, 6));
	setToHit(4);
	setExp(200);
	setAttacks(2);
	setMovementPerRound(1);
	setMonsterType(medium);
	setInitiativeBonus(2);
	setName("Goblin_Lord");

}

GoblinLord::~GoblinLord()
{
}
