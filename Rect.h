#ifndef Rect_h
#define Rect_h

#include "Shape.h"

class Rect : public Shape{
protected:
    float x;
    float y;
    float w;
    float h;
    
public:
    Rect();
    Rect(float, float, float, float);
    Rect(float, float, float, float, float, float, float);
    
    virtual float getX() const;
    virtual float getY() const;
    virtual float getW() const;
    virtual float getH() const;
    
    virtual void setX(float);
    virtual void setY(float);
    virtual void setH(float);
    virtual void setW(float);
    
    virtual void draw(bool solid = false) const;
    
    virtual bool contains (float, float) const;
};

#endif
