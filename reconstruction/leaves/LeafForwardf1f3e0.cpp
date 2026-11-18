// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1f3e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1f3e0 LeafForwardf1f3e0::Forward
#include "LeafForwardf1f3e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1f3e0::Forward() { return leaf_target(this); }
