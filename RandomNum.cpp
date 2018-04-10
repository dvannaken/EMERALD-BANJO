#include "RandomNum.h"

RandomNum::RandomNum(){
  this->minNum = 4;
  this->maxNum = 4;
}
RandomNum::RandomNum(int min, int max){
  this->minNum = min; // min num;
  this->maxNum = max; // max random num;
  srand(time(NULL));
}
int RandomNum::genRandom(){
	std::mt19937 g(std::random_device{}());
	std::uniform_int_distribution<int> dist(minNum, maxNum);
	return dist(g);  // generates a random num between min and max;
}
int RandomNum::genRandom(int minimum, int maximum){
	std::mt19937 g(std::random_device{}());
	std::uniform_int_distribution<int> dist(minimum, maximum);
	return dist(g);  // generates a random num between min and max; //generates a random num between min and max;
}


int RandomNum::getMinNum()
{
	return minNum;
}

int RandomNum::getMaxNum()
{
	return maxNum;
}


