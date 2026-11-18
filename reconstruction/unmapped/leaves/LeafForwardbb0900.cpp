// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb0900, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb0900 LeafForwardbb0900::Forward
#include "LeafForwardbb0900.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb0900::Forward() { return leaf_target(this); }
