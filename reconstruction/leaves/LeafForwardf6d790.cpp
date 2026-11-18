// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6d790, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6d790 LeafForwardf6d790::Forward
#include "LeafForwardf6d790.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6d790::Forward() { return leaf_target(this); }
