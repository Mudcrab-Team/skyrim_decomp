// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf686a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf686a0 LeafForwardf686a0::Forward
#include "LeafForwardf686a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf686a0::Forward() { return leaf_target(this); }
