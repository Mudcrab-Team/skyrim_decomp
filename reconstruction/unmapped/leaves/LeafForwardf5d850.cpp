// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5d850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5d850 LeafForwardf5d850::Forward
#include "LeafForwardf5d850.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5d850::Forward() { return leaf_target(this); }
