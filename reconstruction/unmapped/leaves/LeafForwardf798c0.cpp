// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf798c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf798c0 LeafForwardf798c0::Forward
#include "LeafForwardf798c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf798c0::Forward() { return leaf_target(this); }
