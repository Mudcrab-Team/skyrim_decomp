// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5e7f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5e7f0 LeafForwardf5e7f0::Forward
#include "LeafForwardf5e7f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5e7f0::Forward() { return leaf_target(this); }
