// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5b180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5b180 LeafForwardf5b180::Forward
#include "LeafForwardf5b180.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5b180::Forward() { return leaf_target(this); }
