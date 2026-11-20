// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7aa40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7aa40 LeafForwardf7aa40::Forward
#include "LeafForwardf7aa40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7aa40::Forward() { return leaf_target(this); }
