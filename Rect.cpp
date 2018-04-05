#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rect::Rect() : Shape() {
    x = -0.2;
    y = 0.2;
    w = 0.4;
    h = 0.4;
}

Rect::Rect(float x, float y, float w, float h) : Shape() {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b) : Shape(r, g, b) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

float Rect::getX() const {
    return x;
}
float Rect::getY() const {
    return y;
}
float Rect::getW() const {
    return w;
}
float Rect::getH() const {
    return h;
}

void Rect::setX(float x) {
    this->x = x;
}
void Rect::setY(float y) {
    this->y = y;
}
void Rect::setW(float w) {
    this->w = w;
}
void Rect::setH(float h) {
    this->h = h;
}

bool Rect::contains(float mx, float my) const {
    return mx >= x && mx <= x + w && my <= y && my >= y - h;
}

void Rect::draw(bool solid) const {
    
    glColor3f(r, g, b);
    
    if (!solid){
        glBegin(GL_LINES);
        
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);
        
        glVertex2f(x, y - h);
        glVertex2f(x, y);
        
        glEnd();
    }
    else{
        glBegin(GL_POLYGON);

        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);
        
        glEnd();
    }
}
