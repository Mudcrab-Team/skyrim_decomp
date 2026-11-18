// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb55f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb55f0 LeafForwardfb55f0::Forward
#include "LeafForwardfb55f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb55f0::Forward() { return leaf_target(this); }
