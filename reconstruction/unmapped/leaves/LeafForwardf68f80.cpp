// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68f80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68f80 LeafForwardf68f80::Forward
#include "LeafForwardf68f80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68f80::Forward() { return leaf_target(this); }
