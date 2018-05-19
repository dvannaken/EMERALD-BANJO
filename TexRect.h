#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    GLuint texture_map_id;
    GLuint temp;
    int rows;
    int cols;
    int curr_row;
    int curr_col;
    float getY();
    float getH();
    float getX();
    float getW();
    void setY(float);
    void setX(float);

    TexRect (const char*, float, float, float, float);
    TexRect (const char*, const char*, int, int, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    bool animating;
    bool complete;
    bool shoot();
    bool done();
    bool shooting;
    bool shot;
    float getShot();
    void setShot(bool);
    
    
    void moveUp(float rate=0.01);
    void moveUpP(float rate=0.09);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    void animate();
    void advance();
    void reset();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
};

#endif
