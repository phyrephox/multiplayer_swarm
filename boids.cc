#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include "boids.h"

using namespace v8;

Persistent<Function> Boids::constructor;

Boids::Boids() {
}

Boids::~Boids() {
}

void Boids::Init(Handle<Object> exports) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Boids"));
  tpl->InstanceTemplate()->SetInternalFieldCount(2);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
      FunctionTemplate::New(PlusOne)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("getNextFrame"),
      FunctionTemplate::New(GetNextFrame)->GetFunction());
  constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Boids"), constructor);
}

Handle<Value> Boids::New(const Arguments& args) {
  HandleScope scope;

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    //double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    Boids* obj = new Boids();
    obj->Wrap(args.This());
    for (int i=0;i<1000;i++){
     Vector* pos = new Vector(rand()%30+200,rand()%30+200);
     Vector* vel = new Vector(rand()%5-2,rand()%5-2);
     Boid* b = new Boid(*pos,*vel);
     obj->boidset.push_back(b);
    }
    return args.This();
  } else {
    // Invoked as plain function `MyObject(...)`, turn into construct call.
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    return scope.Close(constructor->NewInstance(argc, argv));
  }
}

Handle<Value> Boids::PlusOne(const Arguments& args) {
  HandleScope scope;

  //Boids* obj = ObjectWrap::Unwrap<Boids>(args.This());
  //obj->value += 1;

  return scope.Close(Number::New(0));
}

Handle<Value> Boids::GetNextFrame(const Arguments& args){
 HandleScope scope;
 Boids* obj = ObjectWrap::Unwrap<Boids>(args.This());
 Local<Array> objList = Array::New();
 for (int i=0;i<obj->boidset.size();i++){
  obj->boidset[i]->interact(obj->boidset);
 }
 for (int i=0;i<obj->boidset.size();i++){
  Local<Object> temp = Object::New();
  temp->Set(String::New("xpos"),Number::New(obj->boidset[i]->getPos().x));
  temp->Set(String::New("ypos"),Number::New(obj->boidset[i]->getPos().y));
  temp->Set(String::New("xvel"),Number::New(obj->boidset[i]->getVel().x));
  temp->Set(String::New("yvel"),Number::New(obj->boidset[i]->getVel().y));
  objList->Set(i,temp);
 }
 return scope.Close(objList);
}
