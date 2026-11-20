// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68f50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68f50 LeafForwardf68f50::Forward
#include "LeafForwardf68f50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68f50::Forward() { return leaf_target(this); }
