// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78d60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78d60 LeafForwardf78d60::Forward
#include "LeafForwardf78d60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78d60::Forward() { return leaf_target(this); }
