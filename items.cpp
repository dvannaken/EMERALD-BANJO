#include "Items.h"

Item::Item():Entity(0,0)
{
	//objectTex = new TexRect(filename,x,y,w,h);
}

Item::Item(int x, int y):Entity(x,y)
{
	//objectTex = new TexRect(filename,x,y,w,h);
}

Item::~Item()
{
}

void Item::spawnItem(int x, int y)
{
	setX(x);
	setY(y);
}

void Item::destroyItem()
{
}

bool Item::isOnBoard()
{
	return onBoard;
}

bool Item::onPlayer()
{
	return equiped;
}

void Item::setEquiped(bool equip)
{
	this->equiped = equip;
}
