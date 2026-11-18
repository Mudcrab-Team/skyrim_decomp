// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf686c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf686c0 LeafForwardf686c0::Forward
#include "LeafForwardf686c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf686c0::Forward() { return leaf_target(this); }
