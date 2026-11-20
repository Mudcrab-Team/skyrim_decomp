// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf60a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf60a60 LeafForwardf60a60::Forward
#include "LeafForwardf60a60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf60a60::Forward() { return leaf_target(this); }
