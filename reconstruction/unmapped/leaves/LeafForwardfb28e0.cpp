// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb28e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb28e0 LeafForwardfb28e0::Forward
#include "LeafForwardfb28e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb28e0::Forward() { return leaf_target(this); }
