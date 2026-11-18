// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbc0a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbc0a0 LeafForwardfbc0a0::Forward
#include "LeafForwardfbc0a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbc0a0::Forward() { return leaf_target(this); }
