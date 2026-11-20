// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbc37a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbc37a0 LeafForwardbc37a0::Forward
#include "LeafForwardbc37a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbc37a0::Forward() { return leaf_target(this); }
