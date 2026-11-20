// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3b2bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3b2bb0 LeafForward3b2bb0::Forward
#include "LeafForward3b2bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward3b2bb0::Forward() { return leaf_target(this); }
