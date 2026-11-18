// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0a900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0a900 LeafForwardf0a900::Forward
#include "LeafForwardf0a900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0a900::Forward() { return leaf_target(this); }
