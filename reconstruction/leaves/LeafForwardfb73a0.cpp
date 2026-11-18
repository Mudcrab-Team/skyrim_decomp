// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb73a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb73a0 LeafForwardfb73a0::Forward
#include "LeafForwardfb73a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb73a0::Forward() { return leaf_target(this); }
