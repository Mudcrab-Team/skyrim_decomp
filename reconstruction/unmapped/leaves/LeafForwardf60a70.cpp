// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf60a70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf60a70 LeafForwardf60a70::Forward
#include "LeafForwardf60a70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf60a70::Forward() { return leaf_target(this); }
