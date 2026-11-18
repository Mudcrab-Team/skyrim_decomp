// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeba0a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeba0a0 LeafForwardeba0a0::Forward
#include "LeafForwardeba0a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeba0a0::Forward() { return leaf_target(this); }
