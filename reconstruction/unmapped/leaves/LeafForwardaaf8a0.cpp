// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaaf8a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaaf8a0 LeafForwardaaf8a0::Forward
#include "LeafForwardaaf8a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaaf8a0::Forward() { return leaf_target(this); }
