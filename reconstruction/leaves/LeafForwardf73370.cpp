// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73370 LeafForwardf73370::Forward
#include "LeafForwardf73370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73370::Forward() { return leaf_target(this); }
