// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7bfe0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7bfe0 LeafForwardf7bfe0::Forward
#include "LeafForwardf7bfe0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7bfe0::Forward() { return leaf_target(this); }
