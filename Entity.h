//should hold xy coordinates
#ifndef Entity_h
#define Entity_h

class Entity {
private:
  float x;
  float y;

public:
  float getX() const;
  float getY() const ;

  void setX(float);
  void setY(float);

};


#endif
