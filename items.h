#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <vector>

/*enum class Items {
  Shield,
  Sword,
  Healing Elixr,
  // any other items?
};
*/

class Item {
protected:
  string ItemName;

public:
  Item();
  ~Item();

  string getItemName();
};

class Protection : public Item {
protected:
  int defense; //blocks certain amount of damage

public:
  Protection();
  ~Protection();

  int getDefense(); //defense function
};

class Weapon : public Item {
protected:
  int damage;
public:
  Weapon();
  ~Weapon();

  int getDamage();
};

class Elixr : pubic Item {
protected:
  int heal; //or a function that heals character to max
public:
  Elixr();
  ~Elixr();

  int restoreHealth();
};

vector<Item*> Inventory;
Protection* shield = new Protection();
Weapon* sword = new Weapon();
Elixr* potion = new Elixr();

Inventory.pushback(shield);
Inventory.pushback(sword);
Inventory.pushback(potion);
