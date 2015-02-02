class Vector {
 public:
  double x,y;
  Vector();
  Vector(double, double);
  Vector(const Vector&);
  void set(double, double);
  void set(const Vector&);
  Vector get();
  double mag();
  double angle();
  Vector add(Vector v);
  Vector add(double, double);
  Vector sub(Vector v);
  Vector mult(double);
  Vector div(double);
  double dist(Vector);
  Vector norm();
  Vector limit(double, double);
  
  static Vector add(Vector,Vector);
  static Vector sub(Vector,Vector);
  static double dist(Vector,Vector);
};
