// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97f20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97f20 LeafForwardf97f20::Forward
#include "LeafForwardf97f20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97f20::Forward() { return leaf_target(this); }
