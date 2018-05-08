#ifndef ItemManger_HPP
#define ItemManger_HPP
#include "Weapons.h"
#include "Armor.h"
#include "Potion.h"
#include <vector>

enum ItemTypes
{
	weapon_,
	armor_,
	potion_
};

class ItemManger
{
public:
	ItemManger();
	~ItemManger();
	void spawnItem(ItemTypes,int x = 0, int y = 0);
	int itemAt(int, int); // returns the item index at that loaction

	int getNumItems();


	std::vector<Item*> itemList;
private:
	int numItems;
	RandomNum* numGenerator;
};







#endif // !ItemManger_HPP
