// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf68850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf68850 LeafForwardf68850::Forward
#include "LeafForwardf68850.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf68850::Forward() { return leaf_target(this); }
