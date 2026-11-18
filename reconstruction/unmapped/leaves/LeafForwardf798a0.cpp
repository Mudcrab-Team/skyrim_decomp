// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf798a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf798a0 LeafForwardf798a0::Forward
#include "LeafForwardf798a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf798a0::Forward() { return leaf_target(this); }
