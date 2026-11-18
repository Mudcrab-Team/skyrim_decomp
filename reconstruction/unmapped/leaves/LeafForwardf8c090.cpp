// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8c090, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8c090 LeafForwardf8c090::Forward
#include "LeafForwardf8c090.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8c090::Forward() { return leaf_target(this); }
