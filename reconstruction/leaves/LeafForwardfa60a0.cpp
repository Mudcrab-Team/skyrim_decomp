// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa60a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa60a0 LeafForwardfa60a0::Forward
#include "LeafForwardfa60a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa60a0::Forward() { return leaf_target(this); }
