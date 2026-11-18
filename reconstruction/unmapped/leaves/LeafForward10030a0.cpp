// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10030a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10030a0 LeafForward10030a0::Forward
#include "LeafForward10030a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10030a0::Forward() { return leaf_target(this); }
