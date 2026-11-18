// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5f800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5f800 LeafForwardf5f800::Forward
#include "LeafForwardf5f800.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5f800::Forward() { return leaf_target(this); }
