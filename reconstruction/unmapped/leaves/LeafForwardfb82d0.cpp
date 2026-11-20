// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb82d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb82d0 LeafForwardfb82d0::Forward
#include "LeafForwardfb82d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb82d0::Forward() { return leaf_target(this); }
