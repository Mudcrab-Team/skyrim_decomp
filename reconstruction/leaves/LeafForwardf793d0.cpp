// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf793d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf793d0 LeafForwardf793d0::Forward
#include "LeafForwardf793d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf793d0::Forward() { return leaf_target(this); }
