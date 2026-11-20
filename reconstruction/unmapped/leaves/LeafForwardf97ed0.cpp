// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97ed0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97ed0 LeafForwardf97ed0::Forward
#include "LeafForwardf97ed0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97ed0::Forward() { return leaf_target(this); }
