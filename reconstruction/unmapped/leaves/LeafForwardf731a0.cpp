// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf731a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf731a0 LeafForwardf731a0::Forward
#include "LeafForwardf731a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf731a0::Forward() { return leaf_target(this); }
