// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf73170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf73170 LeafForwardf73170::Forward
#include "LeafForwardf73170.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf73170::Forward() { return leaf_target(this); }
