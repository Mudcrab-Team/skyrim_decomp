// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5f810, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5f810 LeafForwardf5f810::Forward
#include "LeafForwardf5f810.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5f810::Forward() { return leaf_target(this); }
