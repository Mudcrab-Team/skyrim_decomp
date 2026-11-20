// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1cf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1cf0 LeafForwardfb1cf0::Forward
#include "LeafForwardfb1cf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1cf0::Forward() { return leaf_target(this); }
