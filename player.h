#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "gameObj.h"
#include "vector.h"

class Player: public GameObj{
 bool accel;
 double angle;
 double brakeAmt;
 
 public:
  Player();
  Player(Vector, Vector);
  void accelerate(double);
  void rotate(double);
  void brake();
  double getAngle();
  void interact(std::vector<GameObj*>, std::vector<int>, double delta);
};

#endif
