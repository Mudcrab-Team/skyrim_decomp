// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb9d80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb9d80 LeafForwardbb9d80::Forward
#include "LeafForwardbb9d80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb9d80::Forward() { return leaf_target(this); }
