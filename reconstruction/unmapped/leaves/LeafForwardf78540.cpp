// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78540 LeafForwardf78540::Forward
#include "LeafForwardf78540.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78540::Forward() { return leaf_target(this); }
