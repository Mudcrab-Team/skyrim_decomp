// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97ef0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97ef0 LeafForwardf97ef0::Forward
#include "LeafForwardf97ef0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97ef0::Forward() { return leaf_target(this); }
