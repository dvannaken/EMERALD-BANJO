#include "Title.h"

Title::Title() {
	dungeon = new TexRect("images/MenuScreenFinal.bmp", -1, 1, 2, 2);
    runner = new AnimatedRect("images/hoodguy2.bmp", 1, 6, 0.65, -0.68, 0.25, 0.25);
	gameOver = new AnimatedRect("../images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
}

Title::~Title() {
	delete dungeon;
	delete runner;
	delete gameOver;
}

void Title::draw() {
	runner->draw();
    dungeon->draw();
}

void Title::animate(char c) {
	switch (c)
	{
	case 'r':
		runner->animate();
		break;
	case 'd':
		dungeon->animate();
		break;
	case 'g':
		gameOver->animate();
		break;
	default:
		break;
	}
}

void Title::advance(char c) {
	switch (c)
	{
	case 'r':
		runner->advance();
		break;
	case 'd':
		dungeon->advance();
		break;
	case 'g':
		gameOver->advance();
		break;
	default:
		break;
	}
}

bool Title::done(char c) {
	switch (c)
	{
	case 'r':
		return runner->done();
	case 'd':
		return dungeon->done();
	case 'g':
		return gameOver->done();
	default:
		return false;
	}
}