// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb7810, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb7810 LeafForwardfb7810::Forward
#include "LeafForwardfb7810.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb7810::Forward() { return leaf_target(this); }
