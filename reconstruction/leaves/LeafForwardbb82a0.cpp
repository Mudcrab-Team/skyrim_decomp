// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb82a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb82a0 LeafForwardbb82a0::Forward
#include "LeafForwardbb82a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb82a0::Forward() { return leaf_target(this); }
