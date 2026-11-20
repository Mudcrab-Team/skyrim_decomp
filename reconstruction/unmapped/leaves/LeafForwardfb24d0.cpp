// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb24d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb24d0 LeafForwardfb24d0::Forward
#include "LeafForwardfb24d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb24d0::Forward() { return leaf_target(this); }
