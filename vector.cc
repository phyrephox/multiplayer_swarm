#include <math.h>
#include "vector.h"

Vector::Vector(){
 this->x=0;
 this->y=0;
}
Vector::Vector(double x, double y){
 this->x=x;
 this->y=y;
}
Vector::Vector(const Vector& other){
 this->x=other.x;
 this->y=other.y;
}
void Vector::set(double x, double y){
 this->x=x;
 this->y=y;
}
void Vector::set(const Vector& other){
 this->x=other.x;
 this->y=other.y;
}
Vector Vector::get(){
 return *this;
}
double Vector::mag(){
 return sqrt(x*x+y*y);
}
double Vector::angle(){
 return atan2(y,x);
}
Vector Vector::add(Vector v){
 x+=v.x;
 y+=v.y;
 return *this;
}
Vector Vector::add(double x, double y){
 this->x+=x;
 this->y+=y;
 return *this;
}
Vector Vector::sub(Vector v){
 x-=v.x;
 y-=v.y;
 return *this;
}
Vector Vector::mult(double n){
 x*=n;
 y*=n;
 return *this;
}
Vector Vector::div(double n){
 x/=n;
 y/=n;
 return *this;
}
double Vector::dist(Vector v){
 double dx=x-v.x;
 double dy=y-v.y;
 return sqrt(dx*dx+dy*dy);
}
Vector Vector::norm(){
 double m=mag();
 if (m!=0 && m!=1){
  div(m);
 }
 return *this;
}
Vector Vector::limit(double min, double max){
 if (mag()>max){
  norm();
  mult(max);
 } else if(mag()<min){
  norm();
  mult(min);
 }
 return *this;
}
Vector Vector::add(Vector v1,Vector v2){
 return *(new Vector(v1.x+v2.x,v1.y+v2.y));
}
Vector Vector::sub(Vector v1,Vector v2){
 return *(new Vector(v1.x-v2.x,v1.y-v2.y));
}
double Vector::dist(Vector v1,Vector v2){
 double dx=v1.x-v2.x;
 double dy=v1.y-v2.y;
 return sqrt(dx*dx+dy*dy);
}
