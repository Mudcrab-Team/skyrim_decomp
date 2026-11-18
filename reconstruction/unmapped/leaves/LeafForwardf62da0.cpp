// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf62da0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf62da0 LeafForwardf62da0::Forward
#include "LeafForwardf62da0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf62da0::Forward() { return leaf_target(this); }
