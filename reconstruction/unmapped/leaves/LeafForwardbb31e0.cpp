// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb31e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb31e0 LeafForwardbb31e0::Forward
#include "LeafForwardbb31e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb31e0::Forward() { return leaf_target(this); }
