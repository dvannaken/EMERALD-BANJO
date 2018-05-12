#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    mx = 0.0;
    my = 0.0;
    
    dungeon = new TexRect("images/MenuScreenFinal.bmp", 1, 1, -1, 1, 2, 2);//
    runner = new TexRect("images/hoodguy2.bmp", 1, 6, 0.65, -0.68, 0.25, 0.25);
    //runner = new TexRect("images/run.bmp", 2, 8, 0.65, -0.68, 0.25, 0.25);
    gameBoard = new Board(50);
}

void App::draw() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if(!game.getGameStartStatus()) {
        glColor3d(1.0, 1.0, 1.0); //white background
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
        //std::cout << "inputing" << key <<std::endl;
        gameBoard->handle(key);
        
    }
    redraw();
}

void App::menuScreen() {
    runner->draw();
    dungeon->draw();
}

void App::gameScreen() {
    gameBoard->draw();

    /*
    if(!game.getGameEndStatus()){
        itsOver->draw();
    }
    */
}


void App::running() {
    if (!this->runner->done()) {
        this->runner->advance();
        this->redraw();
    }
}


void App::idle() {

    t = glutGet(GLUT_ELAPSED_TIME);
    delta = t - lastT;

     if(delta >= 9000/60){
        lastT = t;
        running();
    }

    if (!gameBoard->isUpToDate()){
		std::cout << "idling" << std::endl;
        redraw();
    }
    else{
        gameBoard->check();
    }
    
    //redraw();
}
