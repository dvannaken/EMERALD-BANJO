#ifndef Square_h
#define Square_h

#include "Rect.h"
enum ShapeName {X, O, N};

class Square : public Rect {
    Shape* symbol;
    ShapeName symbolName;
public:
    Square();
    Square(float);
    Square(float, float, float);
    Square(float, float, float, float, float, float);
    
    void draw() const;

    
    Shape* getSymbol() const;
    ShapeName getSymbolName() const;
    void clear();
    
    void handle(float x, float y);
    
    ~Square();
};

#endif
