// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7c020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7c020 LeafForwardf7c020::Forward
#include "LeafForwardf7c020.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7c020::Forward() { return leaf_target(this); }
