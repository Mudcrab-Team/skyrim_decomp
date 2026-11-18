// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaa82e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaa82e0 LeafForwardaa82e0::Forward
#include "LeafForwardaa82e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaa82e0::Forward() { return leaf_target(this); }
