// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8d4b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8d4b0 LeafForwardf8d4b0::Forward
#include "LeafForwardf8d4b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8d4b0::Forward() { return leaf_target(this); }
