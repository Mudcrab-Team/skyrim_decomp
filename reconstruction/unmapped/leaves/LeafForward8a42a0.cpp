// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8a42a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8a42a0 LeafForward8a42a0::Forward
#include "LeafForward8a42a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8a42a0::Forward() { return leaf_target(this); }
