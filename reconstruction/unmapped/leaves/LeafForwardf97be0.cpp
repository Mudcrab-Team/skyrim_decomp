// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97be0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97be0 LeafForwardf97be0::Forward
#include "LeafForwardf97be0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97be0::Forward() { return leaf_target(this); }
