#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    int rows = 1;
    int cols = 1;
    int curr_row = 1;
    int curr_col = 1;
public:
    TexRect (const char*, int, int, float, float, float, float);
    void advance();
    void draw();

};

#endif
