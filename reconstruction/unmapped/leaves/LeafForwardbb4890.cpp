// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb4890, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb4890 LeafForwardbb4890::Forward
#include "LeafForwardbb4890.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb4890::Forward() { return leaf_target(this); }
