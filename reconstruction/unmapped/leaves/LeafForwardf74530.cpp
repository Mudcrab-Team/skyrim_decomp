// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf74530, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf74530 LeafForwardf74530::Forward
#include "LeafForwardf74530.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf74530::Forward() { return leaf_target(this); }
