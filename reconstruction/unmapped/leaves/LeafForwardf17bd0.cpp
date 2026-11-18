// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf17bd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf17bd0 LeafForwardf17bd0::Forward
#include "LeafForwardf17bd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf17bd0::Forward() { return leaf_target(this); }
