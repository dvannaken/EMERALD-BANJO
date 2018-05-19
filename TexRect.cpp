#include "TexRect.h"


TexRect::TexRect (const char* filename, float x=0, float y=0, float w=0.5, float h=0.5){
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    rising = false;
    movingLeft = true;
    animating = false;
    shot = false;
    
    xinc = 0.01;
    yinc = 0.01;
    rows = 1;
    cols = 1;
    curr_col = 1;
    curr_col = 1;
    this->temp = texture_id;
}
TexRect::TexRect (const char* filename, const char* filename2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){  //added second argument for const char* named it filename2
    
    glClearColor (0.0, 0.0, 0.0, 0.0);				//copied and pasted   
    glShadeModel(GL_FLAT);					//this whole block from 
    glEnable(GL_DEPTH_TEST);					//below for the 
    								//explosion image 
    texture_map_id = SOIL_load_OGL_texture(
     filename2,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    this->temp = texture_id; // added to make temp the mushroom image
    
    
    this->rows = rows;	//added for 
    this->cols = cols;  //the explosion map
    
    this->x = x; 
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1; //set the current row to 1
    curr_col = 1;// set the current column to 1

    animating = false;
    shot = false;
    
    complete = false; // set the complete boolean for the done function to false
    rising = false;
    movingLeft = true;
    
    xinc = 0.01;
    yinc = 0.01;
    
}

bool TexRect::done(){   //added a done function 
    return complete;   //to return when animation is done
}

bool TexRect::shoot(){
    return shooting;
}

float TexRect::getY(){
    return y;
}
float TexRect::getH(){
    return h;
}
float TexRect::getX(){
    return x;
}
float TexRect::getW(){
    return w;
}
float TexRect::getShot(){
    return shot;
}
void TexRect::setShot(bool s){
    shot = s;
}
void TexRect::setY(float y){
    this->y = y;
}
void TexRect::setX(float x){
    this->x = x;
}


void TexRect::moveUp(float rate){
    y += rate;
    if (y > 0.99){
	y = 0.99;
    }
}

void TexRect::moveUpP(float rate){
    y += rate;
    
}
void TexRect::moveDown(float rate){
    y -= rate;
     if (y - h < -0.99){
        y = -0.99 + h;
    }
}
void TexRect::moveLeft(float rate){
    x -= rate;
    if (x < -0.99){
        x = -0.99;
    }
}
void TexRect::moveRight(float rate){
    x += rate;
    if (x + w > 0.99){
        x = 0.99 - w;
    }
}

void TexRect::jump(){
    if(rising){
        y+=yinc;
        if (movingLeft){
            x -=xinc;
        }
        else {
            x +=xinc;
        }
    }
    else {
        y-=yinc;
        if (movingLeft){
            x -=xinc;
        }
        else{
            x +=xinc;
        }
    }
    
    if (y > 0.99){
        rising = false;
    }
    if ((y-h) < -0.99){
        rising = true;
    }
    if (x < -0.99) {
        movingLeft = false;
       
    }
    if (x+w > 0.99) {
        movingLeft = true;
        
    }
}

/*void TexRect::draw(){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    
    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);
    
    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}*/

void TexRect::draw(){
    glBindTexture( GL_TEXTURE_2D, temp );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    float top, bottom, left, right;  //copied from TextRect.cpp in the explosion_textures folder
    float xinc = 1.0/cols;	     //floats to map from images
    float yinc = 1.0/rows;	     //and to increment depending on amount of rows and columns from image map
    
    if(animating){                  //if else statement to go to the first image of the explosion map or the full mushroom image
        top = 1 - yinc * (curr_row - 1);
        bottom = 1 - yinc * curr_row;
    
        left = xinc * (curr_col - 1);
        right = xinc * curr_col;
    }
    else{
	left = 0;
	bottom = 0;
	top = 1;
	right = 1;
    }
    
    glBegin(GL_QUADS);
    
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

void TexRect::advance(){	//copied from TextRect.cpp in the explosion_textures folder
    if (curr_col < cols){	//function to move through the explosion map
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
    
    if (curr_row == rows && curr_col == cols){		//if statement to know
        complete = true;				//when the map is done
    }
}


bool TexRect::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}




void TexRect::animate(){
    this->temp = texture_map_id;
    animating = true;
}

