// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa42a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa42a0 LeafForwardfa42a0::Forward
#include "LeafForwardfa42a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa42a0::Forward() { return leaf_target(this); }
