// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74e20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74e20 LeafForwardf74e20::Forward
#include "LeafForwardf74e20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74e20::Forward() { return leaf_target(this); }
