// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74520 LeafForwardf74520::Forward
#include "LeafForwardf74520.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74520::Forward() { return leaf_target(this); }
