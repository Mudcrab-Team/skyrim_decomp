// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7aa20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7aa20 LeafForwardf7aa20::Forward
#include "LeafForwardf7aa20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7aa20::Forward() { return leaf_target(this); }
