// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf798b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf798b0 LeafForwardf798b0::Forward
#include "LeafForwardf798b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf798b0::Forward() { return leaf_target(this); }
