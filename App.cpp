#include "App.h"

static App* singleton;

void running(int value) {
    if (!singleton->titleScreen->done('r')) {
        singleton->titleScreen->advance('r');
        glutTimerFunc(16, running, value);
    }
}

void app_timer(int value) {
    if (singleton->gameBoard->getGameOver()) {
        singleton->titleScreen->advance('g');
    }
/*
    else {
        float bx = singleton->ball->x + singleton->ball->w/2;
        float by = singleton->ball->y - singleton->ball->h + 0.1;
        if (singleton->platform->contains(bx, by)){
            singleton->ball->rising = true;
            singleton->ball->yinc +=0.005;
            singleton->ball->xinc = singleton->ball->yinc;
            if (singleton->ball->yinc > 0.15){
                singleton->ball->yinc = 0.15;
            }
        }
        
        if (singleton->ball->y - singleton->ball->h < -0.99){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
            
        }
    }
    if (singleton->up){
        singleton->platform->moveUp(0.05);
    }
    if (singleton->down){
        singleton->platform->moveDown(0.05);
    }
    if (singleton->left){
        singleton->platform->moveLeft(0.05);
    }
    if (singleton->right){
        singleton->platform->moveRight(0.05);
    }
*/    
    if (singleton->gameBoard->getGameOver()){
        singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    }
	/*
    else{
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
            singleton->redraw();
            glutTimerFunc(16, app_timer, value);
        }
    }
	*/
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    titleScreen = new Title();
    //runner = new TexRect("images/run.bmp", 2, 8, 0.65, -0.68, 0.25, 0.25);
    gameBoard = new Board(50);
	
	t = 0;
	lastT = 0;
	app_timer(1);
}

void App::draw() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if(!gameBoard->getGameStartStatus()) {
        glColor3d(1.0, 1.0, 1.0); //white background
        titleScreen->draw();
    }
    else {
        gameBoard->draw();
    }

    
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
	
	gameBoard->onClick(mx, my);

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){}

void App::keyPress(unsigned char key) {
    if (key == 27){
        delete gameBoard;
        exit(0);
    }
    
    if(!gameBoard->getGameStartStatus()) {
        if((key == 'p') || (key == 'P')){
            gameBoard->setGameStart();
        }
    }
    else {
        //std::cout << "inputing" << key <<std::endl;
        gameBoard->handle(key);
        
    }
    redraw();
}

void App::idle() {

    t = glutGet(GLUT_ELAPSED_TIME);
    delta = t - lastT;

    if(delta >= 9000.0/60.0) {
        lastT = t;
        redraw();
    }

    if (!gameBoard->isUpToDate()){
		std::cout << "idling" << std::endl;
        redraw();
    }
    else{
        gameBoard->tick();
    }
}
