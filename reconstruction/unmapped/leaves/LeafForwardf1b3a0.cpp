// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1b3a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1b3a0 LeafForwardf1b3a0::Forward
#include "LeafForwardf1b3a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1b3a0::Forward() { return leaf_target(this); }
