// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8a210, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8a210 LeafForwardf8a210::Forward
#include "LeafForwardf8a210.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8a210::Forward() { return leaf_target(this); }
