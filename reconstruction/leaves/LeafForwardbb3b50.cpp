// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb3b50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb3b50 LeafForwardbb3b50::Forward
#include "LeafForwardbb3b50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb3b50::Forward() { return leaf_target(this); }
