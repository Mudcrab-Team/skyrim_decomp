// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf811f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf811f0 LeafForwardf811f0::Forward
#include "LeafForwardf811f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf811f0::Forward() { return leaf_target(this); }
