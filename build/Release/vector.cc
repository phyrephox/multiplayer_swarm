#include <math.h>

class Vector {
  double x,y;
 public:
  Vector(double x, double y){
   this.x=x;
   this.y=y;
  }
  void set(double x, double y){
   this.x=x;
   this.y=y;
  }
  Vector get(){
   return this;
  }
  double mag(){
   return sqrt(x*x+y*y);
  }
  double angle(){
   return atan2(y,x);
  }
  
}
