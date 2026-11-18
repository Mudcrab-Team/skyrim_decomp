// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78530, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78530 LeafForwardf78530::Forward
#include "LeafForwardf78530.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78530::Forward() { return leaf_target(this); }
