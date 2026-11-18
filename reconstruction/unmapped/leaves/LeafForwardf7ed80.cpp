// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7ed80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7ed80 LeafForwardf7ed80::Forward
#include "LeafForwardf7ed80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7ed80::Forward() { return leaf_target(this); }
