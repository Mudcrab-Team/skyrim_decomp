// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf61be0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf61be0 LeafForwardf61be0::Forward
#include "LeafForwardf61be0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf61be0::Forward() { return leaf_target(this); }
