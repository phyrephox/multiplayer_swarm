#include <node.h>
#include <vector>
#include <time.h>
#include "boid.h"

class Boids : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);
  
 private:
  explicit Boids();
  ~Boids();
  
  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Persistent<v8::Function> constructor;
  static v8::Handle<v8::Value> PlusOne(const v8::Arguments& args);
  static v8::Handle<v8::Value> GetNextFrame(const v8::Arguments& args);
  //double value;
  std::vector<Boid*> boidset;
};
