// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb40e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb40e0 LeafForwardbb40e0::Forward
#include "LeafForwardbb40e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb40e0::Forward() { return leaf_target(this); }
