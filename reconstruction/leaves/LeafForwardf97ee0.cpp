// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf97ee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf97ee0 LeafForwardf97ee0::Forward
#include "LeafForwardf97ee0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf97ee0::Forward() { return leaf_target(this); }
