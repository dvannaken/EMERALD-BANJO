#include "App.h"

static App* singleton;//

void anim(int value){
    
    if (!singleton->deer->done()){
        singleton->deer->advance();
        singleton->redraw();
        glutTimerFunc(32, anim, value);
    }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    dungeon = new TexRect("MenuScreenFinal.bmp", 1, 1, -1, 1, 2, 2);//
    deer = new TexRect("deer.bmp",2, 4, .35, -.45, 0.25, 0.25);
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
        deer ->draw();
        dungeon -> draw();//
        
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
	//std::cout << "inputing" << key <<std::endl;
    if (key == 27){
        delete gameBoard;
        exit(0);
    }
    
    if (singleton->deer && key == ' '){
        anim(0);
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

void App::menuScreen() {
    //TODO
    
}

void App::gameScreen() {
    gameBoard->draw();
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
