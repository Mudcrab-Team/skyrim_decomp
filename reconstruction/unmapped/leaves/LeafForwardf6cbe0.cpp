// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6cbe0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6cbe0 LeafForwardf6cbe0::Forward
#include "LeafForwardf6cbe0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6cbe0::Forward() { return leaf_target(this); }
