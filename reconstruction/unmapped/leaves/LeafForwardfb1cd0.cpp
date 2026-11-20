// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1cd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1cd0 LeafForwardfb1cd0::Forward
#include "LeafForwardfb1cd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1cd0::Forward() { return leaf_target(this); }
