#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <vector>
#include "vector.h"

class GameObj{
 protected:
  Vector pos;
  Vector vel;
 public:
  GameObj();
  GameObj(Vector, Vector);
  Vector getPos();
  Vector getVel();
  virtual double getAngle(){};
  virtual void interact(std::vector<GameObj*>, std::vector<int>, double delta){};
};

#endif
