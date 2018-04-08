#ifndef RandomNum_h
#define RadnomNum_h

#include <cstdlib>
#include <time.h>
#include <cmath>

class RandomNum{
  int minNum;
  int maxNum;
public:
  RandomNum();
  RandomNum(int, int);
  int genRandom();
  int genRandom(int,int);
};

#endif
