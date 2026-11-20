// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5e810, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5e810 LeafForwardf5e810::Forward
#include "LeafForwardf5e810.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5e810::Forward() { return leaf_target(this); }
