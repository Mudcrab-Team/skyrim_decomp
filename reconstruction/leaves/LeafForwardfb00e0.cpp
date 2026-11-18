// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb00e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb00e0 LeafForwardfb00e0::Forward
#include "LeafForwardfb00e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb00e0::Forward() { return leaf_target(this); }
