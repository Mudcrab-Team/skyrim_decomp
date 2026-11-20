// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1eeb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1eeb0 LeafForwardf1eeb0::Forward
#include "LeafForwardf1eeb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1eeb0::Forward() { return leaf_target(this); }
