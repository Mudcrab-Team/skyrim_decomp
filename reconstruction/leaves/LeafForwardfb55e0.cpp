// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb55e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb55e0 LeafForwardfb55e0::Forward
#include "LeafForwardfb55e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb55e0::Forward() { return leaf_target(this); }
