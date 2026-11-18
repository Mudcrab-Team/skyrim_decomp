// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf61bd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf61bd0 LeafForwardf61bd0::Forward
#include "LeafForwardf61bd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf61bd0::Forward() { return leaf_target(this); }
