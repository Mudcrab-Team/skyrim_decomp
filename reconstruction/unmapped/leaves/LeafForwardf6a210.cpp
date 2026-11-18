// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6a210, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6a210 LeafForwardf6a210::Forward
#include "LeafForwardf6a210.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6a210::Forward() { return leaf_target(this); }
