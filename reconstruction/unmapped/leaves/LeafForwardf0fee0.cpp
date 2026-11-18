// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0fee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0fee0 LeafForwardf0fee0::Forward
#include "LeafForwardf0fee0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0fee0::Forward() { return leaf_target(this); }
