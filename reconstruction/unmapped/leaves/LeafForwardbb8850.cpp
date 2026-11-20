// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb8850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb8850 LeafForwardbb8850::Forward
#include "LeafForwardbb8850.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb8850::Forward() { return leaf_target(this); }
