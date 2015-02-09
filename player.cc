#include "vector.h"
#include "gameObj.h"
#include "player.h"
#include <iostream>
#include <math.h>

#define PI 3.14159

Player::Player(){
 pos.set(0,0);
 vel.set(0,0);
 angle=0;
}

Player::Player(Vector p, Vector v):
 GameObj(p,v)
{
 brakeAmt=.96;
 angle=0;
}

void Player::accelerate(double c){
 vel.add(c*cos(angle), c*sin(angle));
 vel.limit(0,20);
 accel=true;
}

void Player::rotate(double amount){
 angle += amount;
 if (angle>PI){
  angle-=PI*2;
 } else if(angle<-PI){
  angle+=PI*2;
 }
}

void Player::brake(){
 brakeAmt=.7;
}

double Player::getAngle(){
 //std::cout<<"angle"<<angle<<"\n";
 return angle;
}

void Player::interact(std::vector<GameObj*>, std::vector<int> keys, double delta){
 Vector ans (0,0);
 accel=false;
 for (int i=0;i<keys.size();i++){
  int key=keys[i];
  if (key == 38){
   std::cout<<"accel\n";
   accelerate(2.3);
  }else if(key == 40){
   std::cout<<"brake\n";
   brake();
  }else if(key == 37){
   std::cout<<"left\n";
   rotate(-.13);
  }else if(key == 39){
   std::cout<<"right\n";
   rotate(.13);
  }
 }
 pos.add(vel);
 vel.mult(brakeAmt);
 brakeAmt=.96;
}
