// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97bc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97bc0 LeafForwardf97bc0::Forward
#include "LeafForwardf97bc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97bc0::Forward() { return leaf_target(this); }
