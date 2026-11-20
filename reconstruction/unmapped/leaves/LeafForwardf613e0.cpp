// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf613e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf613e0 LeafForwardf613e0::Forward
#include "LeafForwardf613e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf613e0::Forward() { return leaf_target(this); }
