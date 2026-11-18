// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68f40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68f40 LeafForwardf68f40::Forward
#include "LeafForwardf68f40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68f40::Forward() { return leaf_target(this); }
