// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88170 LeafForwardf88170::Forward
#include "LeafForwardf88170.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88170::Forward() { return leaf_target(this); }
