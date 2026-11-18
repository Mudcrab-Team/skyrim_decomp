// Source exposure: binary-analysis; no external implementation reused.
// LeafForward130a330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x130a330 LeafForward130a330::Forward
#include "LeafForward130a330.h"
extern "C" void* leaf_target(void*);
void* LeafForward130a330::Forward() { return leaf_target(this); }
