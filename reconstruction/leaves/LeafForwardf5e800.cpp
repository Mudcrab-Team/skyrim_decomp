// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5e800, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5e800 LeafForwardf5e800::Forward
#include "LeafForwardf5e800.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5e800::Forward() { return leaf_target(this); }
