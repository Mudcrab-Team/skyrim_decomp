// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf12170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf12170 LeafForwardf12170::Forward
#include "LeafForwardf12170.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf12170::Forward() { return leaf_target(this); }
