// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7d900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7d900 LeafForwardf7d900::Forward
#include "LeafForwardf7d900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7d900::Forward() { return leaf_target(this); }
