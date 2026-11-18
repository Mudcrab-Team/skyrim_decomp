// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf760a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf760a0 LeafForwardf760a0::Forward
#include "LeafForwardf760a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf760a0::Forward() { return leaf_target(this); }
