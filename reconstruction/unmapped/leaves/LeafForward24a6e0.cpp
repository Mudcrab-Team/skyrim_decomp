// Source exposure: binary-analysis; no external implementation reused.
// LeafForward24a6e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x24a6e0 LeafForward24a6e0::Forward
#include "LeafForward24a6e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward24a6e0::Forward() { return leaf_target(this); }
