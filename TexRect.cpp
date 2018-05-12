#include "TexRect.h"


TexRect::TexRect (const char* filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);


    RgbImage theTex( filename );

    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );

  
  //WHY DOESNT THIS WORKKK???!!

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex.GetNumCols(), theTex.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTex.ImageData() );

  
    this->texture_id = texture_id;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->rows = rows;
    this->cols = cols;

}

void TexRect::draw(){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBegin(GL_QUADS);
    float xinc = 1.0/cols;
    float yinc = 1.0/rows;
    float top = 1 - yinc * (curr_row - 1);
    float bottom = 1 - yinc * curr_row;
    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;
    glTexCoord2f(left, bottom);
    glVertex2f(x, y - h);
    glTexCoord2f(left, top);
    glVertex2f(x, y);
    glTexCoord2f(right, top);
    glVertex2f(x+w, y);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w, y - h);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

bool TexRect::done() {
    return complete;
}


void TexRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        curr_row = 1;
        curr_col = 1;
    }
}
