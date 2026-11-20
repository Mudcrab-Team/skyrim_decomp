// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88160 LeafForwardf88160::Forward
#include "LeafForwardf88160.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88160::Forward() { return leaf_target(this); }
