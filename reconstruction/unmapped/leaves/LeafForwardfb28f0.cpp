// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb28f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb28f0 LeafForwardfb28f0::Forward
#include "LeafForwardfb28f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb28f0::Forward() { return leaf_target(this); }
