#include "vector.h"
#include "boid.h"
#include <iostream>

Boid::Boid(){
 pos.set(0,0);
 vel.set(0,0);
 rules.erase(rules.begin(),rules.end());
}

Boid::Boid(Vector p, Vector v):
 GameObj(p,v)
 {
 //pos.set(p);
 //vel.set(v);
 rules.erase(rules.begin(),rules.end());
}

void Boid::separation(std::vector<GameObj*> boidset, double c){
 Vector ans (0,0);
 for (int i=0;i<boidset.size();i++){
  if (this!=boidset[i]){
   if (Vector::dist(pos,boidset[i]->getPos())<5){
    ans.sub(Vector::sub(boidset[i]->getPos(),pos));
   }
  }
 }
 //std::cout<<ans.x<<" "<<ans.y<<"\n";
 rules.push_back(ans.mult(c));
}

void Boid::cohesion(std::vector<GameObj*> boidset, double c){
 Vector ans (0,0);
 int count=0;
 for (int i=0;i<boidset.size();i++){
  if (this!=boidset[i]){
   if (Vector::dist(pos,boidset[i]->getPos())<80){
    count++;
    ans.add(boidset[i]->getPos());
   }
  }
 }
 if (count >0){
  ans.div(count);
  ans.sub(pos);
 }
 //std::cout<<ans.x<<" "<<ans.y<<"\n";
 rules.push_back(ans.mult(c));
}

void Boid::adhesion(std::vector<GameObj*> boidset, double c){
 Vector ans (0,0);
 int count=0;
 for (int i=0;i<boidset.size();i++){
  if (this!=boidset[i]){
   if (Vector::dist(pos,boidset[i]->getPos())<50){
    count++;
    ans.add(boidset[i]->getVel());
   }
  }
 }
 if (count > 0){
  ans.div(count);
  ans.sub(vel);
 }
 //std::cout<<ans.x<<" "<<ans.y<<"\n";
 rules.push_back(ans.mult(c));
}

void Boid::boundary(double c){
 Vector ans (0,0);
 if (pos.x > 1700){
  ans.add(170-pos.x/10.0,0);
 }
 if (pos.x < 100){
  ans.add(10-pos.x/10.0,0);
 }
 if (pos.y > 800){
  ans.add(0,80-pos.y/10.0);
 }
 if (pos.y < 100){
  ans.add(0,10-pos.y/10.0);
 }
 rules.push_back(ans.mult(c));
}


void Boid::interact(std::vector<GameObj*> boidset, std::vector<int> keys, double delta){
 rules.erase(rules.begin(),rules.end());
 separation(boidset, 1.2);
 cohesion(boidset, .01);
 adhesion(boidset, .3);
 boundary(3.6);
 for (int i=0;i<rules.size();i++){
  vel.add(rules[i]);
 }
 vel.limit(0,20);
 Vector velDelt = vel.get();
 velDelt.mult(delta);
 velDelt.div(30);
 pos.add(velDelt);
}
