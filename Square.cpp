#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>

#include "Square.h"

Square::Square() : Rect(){
    symbol = 0;
    symbolName = N;
}
Square::Square(float w) : Rect(0, 0, w, w){
    symbol = 0;
    symbolName = N;
}
Square::Square(float x , float y, float w) : Rect(x, y, w, w) {
    symbol = 0;
    symbolName = N;
}
Square::Square(float x, float y, float w, float r, float g, float b) : Rect(x, y, w, w, r, g, b) {
    symbol = 0;
    symbolName = N;
}

void Square::draw() const {
    
    
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y - h);
    glVertex2f(x, y - h);
    
    glEnd();
}


Shape* Square::getSymbol() const {
    return symbol;
}

ShapeName Square::getSymbolName() const{
    return symbolName;
}
void Square::clear() {
    if (symbol != 0){
        delete symbol;
    }
    symbol = 0;
    symbolName = N;
}

Square::~Square(){
    if (symbol != 0){
        delete symbol;
    }
}
