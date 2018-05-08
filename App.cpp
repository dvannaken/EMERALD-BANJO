#include "App.h"
using namespace std;

static App* singleton;//

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables

    singleton = this;//
    mx = 0.0;
    my = 0.0;

    dungeon = new TexRect("dungeon.bmp", 6, 6, -1, 1, 2, 2);//
    gameBoard = new Board(50);
}

void App::draw() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    ///////////////////////////////////
    if(!game.getGameStartStatus()) {
      glColor3d(1.0, 1.0, 1.0); //white background

      menuScreen();
      dungeon -> draw();//
    }
    else {
        gameScreen();
    }
    ///////////////////////////////////

    glFlush();
    glutSwapBuffers();

}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
	std::cout << "inputing" << key <<std::endl;

    if (key == 27){
        delete gameBoard;
        exit(0);
    }

    if(!game.getGameStartStatus()) {
        if((key == 'p') || (key == 'P')){
            game.setGameStart();
        }
    }

    else {
		std::cout << "inputing" << key <<std::endl;
        gameBoard->handle(key);

    }
    redraw();

}

////////////////////////////
void App::menuScreen() {
    //TODO


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POLYGON); //bottom menu border
	glColor3d(0.0, 1.0, 1.0);
	glVertex2f(-1.0, -0.9);
	glVertex2f(1.0, -0.9);
	glVertex2f(1.0, -1);
	glVertex2f(-1.0, -1);
    	glEnd();

    glBegin(GL_POLYGON); //top menu border
  	glColor3d(0.0, 1.0, 1.0);
  	glVertex2f(-1.0, 0.9);
  	glVertex2f(1.0, 0.9);
  	glVertex2f(1.0, 1);
  	glVertex2f(-1.0, 1);
  	glEnd();

    glBegin(GL_POLYGON); //left menu border
  	glColor3d(0.0, 1.0, 1.0);
  	glVertex2f(-1.0,-1.0);
  	glVertex2f(-.9,-1.0);
  	glVertex2f(-.9, 1.0);
  	glVertex2f(-1.0, 1.0);
  	glEnd();


    glBegin(GL_POLYGON); //Right menu border
        glColor3d(0.0, 1.0, 1.0);
        glVertex2f(1.0,-1.0);
        glVertex2f(.9,-1.0);
        glVertex2f(.9, 1.0);
        glVertex2f(1.0, 1.0);
        glEnd();

    //Menu Options
    glRasterPos2f(-0.25f, -0.05f);
    glColor3f(1.0f, 1.0f, 1.0f);

    string message = "To play, press 'P' or 'p' ";

    for(int i = 0; i < message.length(); ++i)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);


    glFlush();
    glutSwapBuffers();



}

void App::gameScreen() {
    gameBoard->draw();
}
////////////////////////////


void App::idle() {

  /*t = glutGet(GLUT_ELAPSED_TIME); //added this
  delta = t - lastT;
  // Update and redraw the scene when specified timestep passed
  if(delta >= 1000/80) {
      lastT = t;
      updateMenu();
  }
      redraw(); //
*/
    if (!gameBoard->isUpToDate()) {
		std::cout << "idling" << std::endl;
        redraw();
    }
    else{
        gameBoard->check();
    }
}
