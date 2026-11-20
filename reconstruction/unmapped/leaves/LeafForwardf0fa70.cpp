// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0fa70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0fa70 LeafForwardf0fa70::Forward
#include "LeafForwardf0fa70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0fa70::Forward() { return leaf_target(this); }
