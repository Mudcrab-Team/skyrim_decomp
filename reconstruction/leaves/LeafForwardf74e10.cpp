// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74e10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74e10 LeafForwardf74e10::Forward
#include "LeafForwardf74e10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74e10::Forward() { return leaf_target(this); }
