// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf739f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf739f0 LeafForwardf739f0::Forward
#include "LeafForwardf739f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf739f0::Forward() { return leaf_target(this); }
