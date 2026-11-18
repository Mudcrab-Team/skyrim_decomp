// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5f7f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5f7f0 LeafForwardf5f7f0::Forward
#include "LeafForwardf5f7f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5f7f0::Forward() { return leaf_target(this); }
