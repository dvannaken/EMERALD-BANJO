#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
	std::cout << "initing" << '\n';
	gameBoard = new Board();
}

void App::draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gameBoard->draw();

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
        // Exit the app when Esc key is pressed
        exit(0);
    }
	else {
		gameBoard->movementHandle(key);
	}
}

void App::idle() {
	if (!gameBoard->isUpToDate()) {
		redraw();
	}
	else {
		gameBoard->check();
	}

}
