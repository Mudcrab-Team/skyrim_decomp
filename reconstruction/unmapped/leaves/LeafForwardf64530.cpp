// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf64530, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf64530 LeafForwardf64530::Forward
#include "LeafForwardf64530.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf64530::Forward() { return leaf_target(this); }
