// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb1ce0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb1ce0 LeafForwardfb1ce0::Forward
#include "LeafForwardfb1ce0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb1ce0::Forward() { return leaf_target(this); }
