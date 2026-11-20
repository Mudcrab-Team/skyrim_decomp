// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf798e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf798e0 LeafForwardf798e0::Forward
#include "LeafForwardf798e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf798e0::Forward() { return leaf_target(this); }
