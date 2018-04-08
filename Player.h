#include "Entity.h"
#ifndef Player_h
#define Player_h

class Player: public Entity { //must have health element
private:
  int con; //this is the constitution/health
  int chari; //charisma
  int wis; //wisdom/perception
  int dex; //Dexterity
  int intel; //Intelligence
  int stre; //Strength

public:
  int getCon() const;
  int getChari() const;
  int getWis() const;
  int getDex() const;
  int getIntel() const;
  int getStre() const;

  void setCon(int);
  void setChari(int);
  void setWis(int);
  void setDex(int);
  void setIntel(int);
  void setStre(int);

//(virtual) add functions for movement: up, down, left and right
  virtual void moveUp(float x, float y);
  virtual void moveDown(float x, float y);
  virtual void moveLeft(float x, float y);
  virtual void moveRight(float x, float y);

};



#endif
