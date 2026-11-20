// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8b000, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8b000 LeafForwardf8b000::Forward
#include "LeafForwardf8b000.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8b000::Forward() { return leaf_target(this); }
