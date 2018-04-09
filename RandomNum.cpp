#include "RandomNum.h"

RandomNum::RandomNum(){
  this->minNum = 4;
  this->maxNum = 4;
}
RandomNum::RandomNum(int min, int max){
  this->minNum = min; // min num;
  this->maxNum = max; // max random num;
}
int RandomNum::genRandom(){
    srand(time(NULL));
    return rand() % maxNum + minNum; // generates a random num between min and max;
}
int RandomNum::genRandom(int minimum, int maximum){
  srand(time(NULL));
  return rand() % maximum + minimum; //generates a random num between min and max;
}

int RandomNum::getMinNum()
{
	return minNum;
}

int RandomNum::getMaxNum()
{
	return maxNum;
}
