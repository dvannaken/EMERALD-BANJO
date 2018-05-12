#ifndef Items_HPP
#define Items_HPP
#include "Entity.h"
#include "RandomNum.h"

class Item: public Entity
{
public:
	Item();
	Item(int, int);
	~Item();
	void spawnItem(int, int); // spawns itmes at x, y
	void destroyItem();
	bool isOnBoard();
	bool onPlayer();
	void setEquiped(bool);


private:
	bool onBoard;
	bool equiped;

};

#endif // !Items_HPP
