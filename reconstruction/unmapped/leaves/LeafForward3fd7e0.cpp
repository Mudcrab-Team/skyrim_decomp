// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3fd7e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3fd7e0 LeafForward3fd7e0::Forward
#include "LeafForward3fd7e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward3fd7e0::Forward() { return leaf_target(this); }
