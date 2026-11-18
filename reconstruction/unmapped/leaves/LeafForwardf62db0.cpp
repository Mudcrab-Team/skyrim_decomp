// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf62db0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf62db0 LeafForwardf62db0::Forward
#include "LeafForwardf62db0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf62db0::Forward() { return leaf_target(this); }
