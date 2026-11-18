// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb28c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb28c0 LeafForwardfb28c0::Forward
#include "LeafForwardfb28c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb28c0::Forward() { return leaf_target(this); }
