// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74f40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74f40 LeafForwardf74f40::Forward
#include "LeafForwardf74f40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74f40::Forward() { return leaf_target(this); }
