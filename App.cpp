#include "App.h"

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
    
    if(!game.getGameStartStatus()) {
        menuScreen();
    }
    else {
        gameScreen();
    }
    
    
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
    else {
		std::cout << "inputing" << key <<std::endl;
        gameBoard->handle(key);
    }
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

void App::menuScreen() {
    //TODO
}

void App::gameScreen() {
    gameBoard->draw();
}
