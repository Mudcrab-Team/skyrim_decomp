// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd77a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd77a0 LeafForwardbd77a0::Forward
#include "LeafForwardbd77a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd77a0::Forward() { return leaf_target(this); }
