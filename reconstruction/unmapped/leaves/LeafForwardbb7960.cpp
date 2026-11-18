// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb7960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb7960 LeafForwardbb7960::Forward
#include "LeafForwardbb7960.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb7960::Forward() { return leaf_target(this); }
