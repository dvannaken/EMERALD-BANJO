#ifndef MonsterList_HPP
#define MonsterList_hpp
#include "Monster.h"

class Goblin : public Monster {
public:
	Goblin(int, int);
	~Goblin();
};

class GoblinLord :public Monster {
public:
	GoblinLord(int, int);
	~GoblinLord();

};


#endif // !Monster_HPP
