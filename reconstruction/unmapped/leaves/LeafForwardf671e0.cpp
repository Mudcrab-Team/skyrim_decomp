// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf671e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf671e0 LeafForwardf671e0::Forward
#include "LeafForwardf671e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf671e0::Forward() { return leaf_target(this); }
