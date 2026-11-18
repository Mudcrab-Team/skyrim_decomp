// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb20e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb20e0 LeafForwardfb20e0::Forward
#include "LeafForwardfb20e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb20e0::Forward() { return leaf_target(this); }
