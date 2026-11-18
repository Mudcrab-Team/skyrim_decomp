// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb28d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb28d0 LeafForwardfb28d0::Forward
#include "LeafForwardfb28d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb28d0::Forward() { return leaf_target(this); }
