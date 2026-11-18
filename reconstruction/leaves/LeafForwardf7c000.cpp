// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7c000, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7c000 LeafForwardf7c000::Forward
#include "LeafForwardf7c000.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7c000::Forward() { return leaf_target(this); }
