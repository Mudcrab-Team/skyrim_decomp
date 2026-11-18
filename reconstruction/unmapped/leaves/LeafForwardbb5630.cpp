// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb5630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb5630 LeafForwardbb5630::Forward
#include "LeafForwardbb5630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb5630::Forward() { return leaf_target(this); }
