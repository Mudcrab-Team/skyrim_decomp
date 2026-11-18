// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5d840, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5d840 LeafForwardf5d840::Forward
#include "LeafForwardf5d840.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5d840::Forward() { return leaf_target(this); }
