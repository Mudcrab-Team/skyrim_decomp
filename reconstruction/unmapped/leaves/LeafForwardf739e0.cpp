// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf739e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf739e0 LeafForwardf739e0::Forward
#include "LeafForwardf739e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf739e0::Forward() { return leaf_target(this); }
