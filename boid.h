#ifndef BOID_H
#define BOID_H

#include <vector>
#include "gameObj.h"
#include "vector.h"

class Boid: public GameObj{
 std::vector<Vector> rules;
 void separation(std::vector<GameObj*>, double);
 void cohesion(std::vector<GameObj*>, double);
 void adhesion(std::vector<GameObj*>, double);
 void boundary(double);
 public:
  Boid();
  Boid(Vector, Vector);
  void interact(std::vector<GameObj*>, std::vector<int>, double delta);
};

#endif
