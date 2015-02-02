#define BUILDINNG_NODE_EXTENSION
#include <node.h>
#include "boids.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
 Boids::Init(exports);
}

NODE_MODULE(addon, InitAll)
