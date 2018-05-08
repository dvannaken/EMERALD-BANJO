#include "ItemManger.h"
ItemManger::ItemManger()
{
	itemList = new std::vector<Item*>;
	numGenerator = new RandomNum();
}

ItemManger::~ItemManger()
{
	for (int i = 0; i < itemList->size(); i++)
	{
		delete itemList[i];
	}

	delete itemList;
	delete numGenerator;
}

void ItemManger::spawnItem(ItemTypes type)
{
	int x = numGenerator->randomInt(100);
	switch (type)
	{
	case weapon:
		if (x < 99)
		{
			switch (numGenerator->randomInt(5))
			{
			case 1:
				itemList->push_back(new BattleAxe());

			}
		}
		






		break;
	case armor:
		break;
	case potion:
		break;
	default:
		break;
	}
}

void ItemManger::spawnItem(ItemTypes, int, int)
{
}
