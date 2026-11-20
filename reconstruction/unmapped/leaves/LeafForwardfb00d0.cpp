// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb00d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb00d0 LeafForwardfb00d0::Forward
#include "LeafForwardfb00d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb00d0::Forward() { return leaf_target(this); }
