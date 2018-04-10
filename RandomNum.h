#ifndef RandomNum_HPP
#define RandomNum_HPP

#include <random>
#include <cstdlib>
#include <cmath>

class RandomNum{
	
  int minNum;
  int maxNum;

public:
  RandomNum();
  RandomNum(int, int);
  int genRandom();
  int genRandom(int,int);
  int getMinNum();
  int getMaxNum();
};

#endif
