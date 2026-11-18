// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7a2e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7a2e0 LeafForwardf7a2e0::Forward
#include "LeafForwardf7a2e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7a2e0::Forward() { return leaf_target(this); }
