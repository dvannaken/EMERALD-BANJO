#ifndef Shape_h
#define Shape_h

class Shape {
protected:
    float r;
    float g;
    float b;
    
public:
    Shape ();
    Shape (float, float, float);
    virtual void draw() const {}
};

#endif
