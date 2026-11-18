// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb4a20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb4a20 LeafForwardbb4a20::Forward
#include "LeafForwardbb4a20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb4a20::Forward() { return leaf_target(this); }
