// Source exposure: binary-analysis; no external implementation reused.
// LeafForward15298f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x15298f0 LeafForward15298f0::Forward
#include "LeafForward15298f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward15298f0::Forward() { return leaf_target(this); }
