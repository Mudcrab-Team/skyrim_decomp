// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68f60 LeafForwardf68f60::Forward
#include "LeafForwardf68f60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68f60::Forward() { return leaf_target(this); }
