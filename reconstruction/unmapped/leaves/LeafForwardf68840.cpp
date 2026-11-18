// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68840, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68840 LeafForwardf68840::Forward
#include "LeafForwardf68840.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68840::Forward() { return leaf_target(this); }
