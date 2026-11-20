// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0a910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0a910 LeafForwardf0a910::Forward
#include "LeafForwardf0a910.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0a910::Forward() { return leaf_target(this); }
