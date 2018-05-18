#include "ItemManger.h"
#include <iostream>
ItemManger::ItemManger()
{
	numItems = 0;
	numGenerator = new RandomNum();
}

ItemManger::~ItemManger()
{
	for (int i = 0; i < WeaponList.size(); i++)
	{
		delete WeaponList[i];
	}
	for (int i = 0; i < ArmorList.size(); i++)
	{
		delete ArmorList[i];
	}
	for (int i = 0; i < PotionList.size(); i++)
	{
		delete PotionList[i];
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
			case 0:
				WeaponList.push_back(new BattleAxe(x, y, bonusmod));
				break;
			case 1:
				WeaponList.push_back(new GreatAxe(x, y, bonusmod));
				break;
			case 2:
				WeaponList.push_back(new Greatsword(x, y, bonusmod));
				break;
			case 3:
				WeaponList.push_back(new Longsword(x, y, bonusmod));
				break;
			case 4:
				WeaponList.push_back(new Dagger(x, y, bonusmod));
				break;

			}
		}
		else {
			if (numGenerator->randomBool())
			{
				WeaponList.push_back(new Mjolnir(x, y, 3));

			}
			else
			{
				WeaponList.push_back(new Excalibur(x, y, 3));
			}
		}

		break;
	case armor_:
		if (lootchance < 50)
		{
			switch (numGenerator->randomInt(5))
			{
			case 0:
				ArmorList.push_back(new Leather(x, y, bonusmod));
				break;
			case 1:
				ArmorList.push_back(new StuddedLeather(x, y, bonusmod));
				break;
			case 2:
				ArmorList.push_back(new Hide(x, y, bonusmod));
				break;
			case 3:
				ArmorList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 4:
				ArmorList.push_back(new Chain_Shirt(x, y, bonusmod));
				break;
			}
		}
		else if (lootchance > 50 && lootchance < 75)
		{
			switch (numGenerator->randomInt(5))
			{
			case 0:
				ArmorList.push_back(new Scale_Mail(x, y, bonusmod));
				break;
			case 1:
				ArmorList.push_back(new Breastplate(x, y, bonusmod));
				break;
			case 2:
				ArmorList.push_back(new Chain_Mail(x, y, bonusmod));
				break;
			case 3:
				ArmorList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 4:
				ArmorList.push_back(new WearableShield(x, y, bonusmod));
				break;
			}
		}
		else if (lootchance > 75)
		{

			switch (numGenerator->randomInt(5))
			{
			case 0:
				ArmorList.push_back(new Halfplate(x, y, bonusmod));
				break;
			case 1:
				ArmorList.push_back(new Splint(x, y, bonusmod));
				break;
			case 2:
				ArmorList.push_back(new Plate(x, y, bonusmod));
				break;
			case 3:
				ArmorList.push_back(new Ring_Mail(x, y, bonusmod));
				break;
			case 4:
				ArmorList.push_back(new Chain_Shirt(x, y, bonusmod));
				break;
			}

		}

		break;
	case potion_:

		if (lootchance < 50)
		{
			PotionList.push_back(new HealthPotion(x, y));
		}
		else if (lootchance >= 50 && lootchance < 80)
		{
			PotionList.push_back(new GreaterHealthPotion(x, y));
		}
		else if (lootchance >= 80 && lootchance < 96)
		{
			PotionList.push_back(new SuperiorHealthPotion(x, y));
		}
		else if (lootchance >= 96)
		{
			PotionList.push_back(new SupremeHealthPotion(x, y));
		}

		break;
	default:
		std::cout << "ERROR: ITEMSPAWN FAILED" << std::endl;
		std::cout << "item #" << numItems << " at " << x << ", " << y << std::endl;
		break;
	}
	numItems++;
}

int ItemManger::itemAt(int x, int y, ItemTypes type)
{
	switch (type)
	{
	case weapon_:
		for (int i = 0; i < WeaponList.size(); i++)
		{
			if (x == WeaponList[i]->getX() && y == WeaponList[i]->getY())
			{
				return i;
			}
		}
		break;
	case armor_:
		for (int i = 0; i < ArmorList.size(); i++)
		{
			if (x == ArmorList[i]->getX() && y == ArmorList[i]->getY())
			{
				return i;
			}
		}
		break;
	case potion_:
		for (int i = 0; i < PotionList.size(); i++)
		{
			if (x == PotionList[i]->getX() && y == PotionList[i]->getY())
			{
				return i;
			}
		}
		break;
	default:
		std::cout << "ERROR: ITEMLOOKUP FAILED" << std::endl;
		std::cout << "unknown item at " << x << ", " << y << std::endl;
		break;
	}
	
}

int ItemManger::getNumItems()
{
	return numItems;
}
