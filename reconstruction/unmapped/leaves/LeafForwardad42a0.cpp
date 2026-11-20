// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardad42a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xad42a0 LeafForwardad42a0::Forward
#include "LeafForwardad42a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardad42a0::Forward() { return leaf_target(this); }
