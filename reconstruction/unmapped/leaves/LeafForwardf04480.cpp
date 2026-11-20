// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf04480, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf04480 LeafForwardf04480::Forward
#include "LeafForwardf04480.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf04480::Forward() { return leaf_target(this); }
