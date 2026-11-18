// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb9df0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb9df0 LeafForwardfb9df0::Forward
#include "LeafForwardfb9df0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb9df0::Forward() { return leaf_target(this); }
