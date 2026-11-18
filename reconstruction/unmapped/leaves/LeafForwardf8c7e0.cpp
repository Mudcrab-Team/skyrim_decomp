// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8c7e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8c7e0 LeafForwardf8c7e0::Forward
#include "LeafForwardf8c7e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8c7e0::Forward() { return leaf_target(this); }
