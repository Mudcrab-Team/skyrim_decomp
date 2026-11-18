// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7c650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7c650 LeafForwardf7c650::Forward
#include "LeafForwardf7c650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7c650::Forward() { return leaf_target(this); }
