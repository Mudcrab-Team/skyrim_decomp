// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb24f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb24f0 LeafForwardfb24f0::Forward
#include "LeafForwardfb24f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb24f0::Forward() { return leaf_target(this); }
