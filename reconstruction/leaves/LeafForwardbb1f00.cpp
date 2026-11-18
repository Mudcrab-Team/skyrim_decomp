// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbb1f00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbb1f00 LeafForwardbb1f00::Forward
#include "LeafForwardbb1f00.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbb1f00::Forward() { return leaf_target(this); }
