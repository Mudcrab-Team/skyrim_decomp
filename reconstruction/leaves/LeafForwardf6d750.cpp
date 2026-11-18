// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6d750, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6d750 LeafForwardf6d750::Forward
#include "LeafForwardf6d750.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6d750::Forward() { return leaf_target(this); }
