// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb82e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb82e0 LeafForwardfb82e0::Forward
#include "LeafForwardfb82e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb82e0::Forward() { return leaf_target(this); }
