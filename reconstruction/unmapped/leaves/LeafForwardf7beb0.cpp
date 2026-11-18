// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7beb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7beb0 LeafForwardf7beb0::Forward
#include "LeafForwardf7beb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7beb0::Forward() { return leaf_target(this); }
