// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68f70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68f70 LeafForwardf68f70::Forward
#include "LeafForwardf68f70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68f70::Forward() { return leaf_target(this); }
