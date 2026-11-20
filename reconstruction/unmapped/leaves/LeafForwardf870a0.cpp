// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf870a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf870a0 LeafForwardf870a0::Forward
#include "LeafForwardf870a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf870a0::Forward() { return leaf_target(this); }
