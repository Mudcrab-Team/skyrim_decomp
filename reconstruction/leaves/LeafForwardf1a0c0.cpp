// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1a0c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1a0c0 LeafForwardf1a0c0::Forward
#include "LeafForwardf1a0c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1a0c0::Forward() { return leaf_target(this); }
