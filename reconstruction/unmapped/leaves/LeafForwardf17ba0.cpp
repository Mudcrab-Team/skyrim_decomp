// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf17ba0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf17ba0 LeafForwardf17ba0::Forward
#include "LeafForwardf17ba0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf17ba0::Forward() { return leaf_target(this); }
