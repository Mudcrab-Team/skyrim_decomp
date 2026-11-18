// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5ba7a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5ba7a0 LeafForward5ba7a0::Forward
#include "LeafForward5ba7a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5ba7a0::Forward() { return leaf_target(this); }
