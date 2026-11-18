// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb5bd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb5bd0 LeafForwardfb5bd0::Forward
#include "LeafForwardfb5bd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb5bd0::Forward() { return leaf_target(this); }
