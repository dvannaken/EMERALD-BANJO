#include "Player.h"
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

//getters
int Player::getCon() const {
  return con;
}

int Player::getChari() const {
  return chari;
}

int Player::getWis() const {
  return wis;
}

int Player::getDex() const {
  return dex;
}

int Player::getIntel() const {
  return intel;
}

int Player::getStre() const {
  return stre;
}

//setters
void Player::setCon(int con) {
  this->con = con;
}

void Player::setChari(int chari) {
  this->chari = chari;
}

void Player::setWis(int wis) {
  this->wis = wis;
}

void Player::setDex(int dex) {
  this->dex = dex;
}

void Player::setIntel(int intel) {
  this->intel = intel;
}

void Player::setStre(int stre) {
  this->stre = stre;
}

//we're gonna use 2d array, so like 2 for loops???
void Player::moveUp(float x, float y) {

}

void Player::moveDown(float x, float y) {

}

void Player::moveLeft(float x, float y) {

}

void Player::moveRight(float x, float y) {

}
