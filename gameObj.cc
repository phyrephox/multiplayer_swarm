#include "gameObj.h"
#include <iostream>

GameObj::GameObj(){
 pos.set(0,0);
 vel.set(0,0);
}

GameObj::GameObj(Vector p, Vector v){
 pos.set(p);
 vel.set(v);
}

Vector GameObj::getPos(){
 Vector p (pos);
 return p;
}

Vector GameObj::getVel(){
 Vector v (vel);
 return v;
}
