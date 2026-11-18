// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardefd3a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xefd3a0 LeafForwardefd3a0::Forward
#include "LeafForwardefd3a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardefd3a0::Forward() { return leaf_target(this); }
