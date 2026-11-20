// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb16a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb16a0 LeafForwardfb16a0::Forward
#include "LeafForwardfb16a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb16a0::Forward() { return leaf_target(this); }
