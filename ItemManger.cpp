#include "ItemManger.h"
ItemManger::ItemManger()
{
	numGenerator = new RandomNum();
}

ItemManger::~ItemManger()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		delete itemList[i];
	}

	//delete itemList;
	delete numGenerator;
}



void ItemManger::spawnItem(ItemTypes type, int x, int y)
{
	int lootchance = numGenerator->randomInt(100);
	int bonusModNumber = numGenerator->randomInt(1000);
	int bonusmod = 0;
	if (bonusModNumber > 700)
	{
		bonusmod = 1;
	}
	else if (bonusModNumber > 900)
	{
		bonusmod = 2;
	}
	else if (bonusModNumber > 950)
	{
		bonusmod = 3;
	}
	switch (type)
	{
	case weapon_:
		if (lootchance < 99)
		{
			switch (numGenerator->randomInt(5))
			{
			case 1:
				itemList.push_back(new BattleAxe(x, y, bonusmod));
				break;
			case 2:
				itemList.push_back(new GreatAxe(x, y, bonusmod));
				break;
			case 3:
				itemList.push_back(new Greatsword(x, y, bonusmod));
				break;
			case 4:
				itemList.push_back(new Longsword(x, y, bonusmod));
				break;
			case 5:
				itemList.push_back(new Dagger(x, y, bonusmod));
				break;

			}
		}
		else {
			if (numGenerator->randomBool())
			{
				itemList.push_back(new Mjolnir(x, y, 3));

			}
			else
			{
				itemList.push_back(new Excalibur(x, y, 3));
			}
		}

		break;
	case armor_:
		if (lootchance < 50)
		{
			switch (numGenerator->randomInt(5))
			{
			case 1:
				itemList.push_back(new Leather(x, y, bonusmod));
				break;
			case 2:
				itemList.push_back(new StuddedLeather(x, y, bonusmod));
				break;
			case 3:
				itemList.push_back(new Hide(x, y, bonusmod));
				break;
			case 4:
				itemList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 5:
				itemList.push_back(new Chain_Shirt(x, y, bonusmod));
				break;
			default:
				break;
			}
		}
		else if (lootchance > 50 && lootchance < 75)
		{
			switch (numGenerator->randomInt(5))
			{
			case 1:
				itemList.push_back(new Scale_Mail(x, y, bonusmod));
				break;
			case 2:
				itemList.push_back(new Breastplate(x, y, bonusmod));
				break;
			case 3:
				itemList.push_back(new Chain_Mail(x, y, bonusmod));
				break;
			case 4:
				itemList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 5:
				itemList.push_back(new WearableShield(x, y, bonusmod));
				break;
			default:
				break;
			}
		}
		else if (lootchance > 75)
		{

			switch (numGenerator->randomInt(5))
			{
			case 1:
				itemList.push_back(new Halfplate(x, y, bonusmod));
				break;
			case 2:
				itemList.push_back(new Splint(x, y, bonusmod));
				break;
			case 3:
				itemList.push_back(new Plate(x, y, bonusmod));
				break;
			case 4:
				itemList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 5:
				itemList.push_back(new Chain_Shirt(x, y, bonusmod));
				break;
			default:
				break;
			}

		}

		break;
	case potion_:

		if (lootchance < 50)
		{
			itemList.push_back(new HealthPotion(x, y));
		}
		else if (lootchance > 50 && lootchance < 80)
		{
			itemList.push_back(new GreaterHealthPotion(x, y));
		}
		else if (lootchance > 80 && lootchance < 96)
		{
			itemList.push_back(new SuperiorHealthPotion(x, y));
		}
		else if (lootchance > 96 && lootchance < 100)
		{
			itemList.push_back(new SupremeHealthPotion(x, y));
		}

		break;
	default:
		break;
	}
}

int ItemManger::itemAt(int x, int y)
{
	for (int i = 0; i < itemList.size(); i++)
	{
		if (x == itemList[i]->getX() && y == itemList[i]->getY() )
		{
			return i;
		}
	}
}

