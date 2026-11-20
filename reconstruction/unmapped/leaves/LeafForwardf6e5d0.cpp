// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6e5d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6e5d0 LeafForwardf6e5d0::Forward
#include "LeafForwardf6e5d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6e5d0::Forward() { return leaf_target(this); }
