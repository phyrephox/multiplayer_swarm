#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

Handle<Value> Method2(const Arguments& args) {
  HandleScope scope;
  char str[10];
  Local<String> x = String::New("x");
  Local<Number> num = Number::New(args[0]->ToObject()->Get(x)->NumberValue());
  return scope.Close(num);
  if (args[0]->ToObject()->Get(x)->IsNumber()){
   return scope.Close(String::New("is"));
  } else {
   return scope.Close(String::New("is not"));
  }
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
  exports->Set(String::NewSymbol("foo"),
      FunctionTemplate::New(Method2)->GetFunction());
}

NODE_MODULE(hello, init)
