// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8a250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8a250 LeafForwardf8a250::Forward
#include "LeafForwardf8a250.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8a250::Forward() { return leaf_target(this); }
