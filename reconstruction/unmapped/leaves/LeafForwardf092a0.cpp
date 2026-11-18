// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf092a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf092a0 LeafForwardf092a0::Forward
#include "LeafForwardf092a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf092a0::Forward() { return leaf_target(this); }
