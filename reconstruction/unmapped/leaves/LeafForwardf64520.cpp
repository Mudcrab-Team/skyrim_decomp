// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf64520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf64520 LeafForwardf64520::Forward
#include "LeafForwardf64520.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf64520::Forward() { return leaf_target(this); }
