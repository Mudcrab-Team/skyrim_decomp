// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7bee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7bee0 LeafForwardf7bee0::Forward
#include "LeafForwardf7bee0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7bee0::Forward() { return leaf_target(this); }
