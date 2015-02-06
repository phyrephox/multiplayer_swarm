#include "vector.h"
#include <vector>

class Boid{
 Vector pos;
 Vector vel;
 std::vector<Vector> rules;
 void separation(std::vector<Boid*>, double);
 void cohesion(std::vector<Boid*>, double);
 void adhesion(std::vector<Boid*>, double);
 void boundary(double);
 public:
  Boid();
  Boid(Vector, Vector);
  Vector getPos();
  Vector getVel();
  void interact(std::vector<Boid*>, double delta);
};
