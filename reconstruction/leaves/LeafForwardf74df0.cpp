// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74df0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74df0 LeafForwardf74df0::Forward
#include "LeafForwardf74df0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74df0::Forward() { return leaf_target(this); }
