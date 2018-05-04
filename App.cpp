#include "App.h"
using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    gameBoard = new Board(50);
}

void App::draw() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    ///////////////////////////////////
    if(!game.getGameStartStatus()) {
        menuScreen();
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
    /*
    else {
		std::cout << "inputing" << key <<std::endl;
        gameBoard->handle(key);
    }
    */
    
    redraw();
}

void App::idle() {
    if (!gameBoard->isUpToDate()){
		std::cout << "idling" << std::endl;
        redraw();
    }
    else{
        gameBoard->check();
    }
    
}

////////////////////////////
void App::menuScreen() {
    //TODO
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //Menu Options
    glRasterPos2f(-0.85f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    string firstLine  = "Welcome";
    string seconfLine = "To play, press 'P' or 'p' ";

    
    for(int i = 0; i < firstLine.length(); ++i)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, firstLine[i]);
    
    glRasterPos2f(-0.25f, -0.05f);
    for(int i = 0; i < seconfLine.length(); ++i)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, seconfLine[i]);
    
    glFlush();
    glutSwapBuffers();

}

void App::gameScreen() {
    gameBoard->draw();
}
////////////////////////////
