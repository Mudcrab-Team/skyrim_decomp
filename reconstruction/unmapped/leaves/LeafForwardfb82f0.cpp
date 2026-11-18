// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb82f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb82f0 LeafForwardfb82f0::Forward
#include "LeafForwardfb82f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb82f0::Forward() { return leaf_target(this); }
