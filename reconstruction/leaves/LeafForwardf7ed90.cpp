// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7ed90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7ed90 LeafForwardf7ed90::Forward
#include "LeafForwardf7ed90.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7ed90::Forward() { return leaf_target(this); }
