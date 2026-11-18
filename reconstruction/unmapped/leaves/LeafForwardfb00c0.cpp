// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb00c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb00c0 LeafForwardfb00c0::Forward
#include "LeafForwardfb00c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb00c0::Forward() { return leaf_target(this); }
