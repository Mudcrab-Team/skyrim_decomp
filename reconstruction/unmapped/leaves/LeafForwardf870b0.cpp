// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf870b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf870b0 LeafForwardf870b0::Forward
#include "LeafForwardf870b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf870b0::Forward() { return leaf_target(this); }
