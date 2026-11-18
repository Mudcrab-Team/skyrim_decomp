// Source exposure: binary-analysis; no external implementation reused.
// LeafForward9ecea0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x9ecea0 LeafForward9ecea0::Forward
#include "LeafForward9ecea0.h"
extern "C" void* leaf_target(void*);
void* LeafForward9ecea0::Forward() { return leaf_target(this); }
