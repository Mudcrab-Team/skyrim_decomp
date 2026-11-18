// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb2a80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb2a80 LeafForwardbb2a80::Forward
#include "LeafForwardbb2a80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb2a80::Forward() { return leaf_target(this); }
