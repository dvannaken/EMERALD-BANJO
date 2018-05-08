#ifndef ItemManger_HPP
#define ItemManger_HPP
#include "Weapons.h"
#include "Armor.h"
#include "Potion.h"
#include <vector>

enum ItemTypes
{
	weapon,
	armor,
	potion
};

class ItemManger
{
public:
	ItemManger();
	~ItemManger();
	void spawnItem(ItemTypes);
	void spawnItem(ItemTypes,int, int);

private:
	std::vector<Item*> *itemList;
	RandomNum* numGenerator;
};







#endif // !ItemManger_HPP
