// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbb1a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbb1a0 LeafForwardfbb1a0::Forward
#include "LeafForwardfbb1a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbb1a0::Forward() { return leaf_target(this); }
