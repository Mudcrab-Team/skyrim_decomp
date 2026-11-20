// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5f830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5f830 LeafForwardf5f830::Forward
#include "LeafForwardf5f830.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5f830::Forward() { return leaf_target(this); }
