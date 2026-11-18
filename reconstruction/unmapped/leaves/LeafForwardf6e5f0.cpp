// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6e5f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6e5f0 LeafForwardf6e5f0::Forward
#include "LeafForwardf6e5f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6e5f0::Forward() { return leaf_target(this); }
