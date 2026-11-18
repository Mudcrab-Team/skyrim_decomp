// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74f50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74f50 LeafForwardf74f50::Forward
#include "LeafForwardf74f50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74f50::Forward() { return leaf_target(this); }
