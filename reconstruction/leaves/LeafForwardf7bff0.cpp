// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7bff0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7bff0 LeafForwardf7bff0::Forward
#include "LeafForwardf7bff0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7bff0::Forward() { return leaf_target(this); }
