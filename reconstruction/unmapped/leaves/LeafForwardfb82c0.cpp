// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfb82c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfb82c0 LeafForwardfb82c0::Forward
#include "LeafForwardfb82c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfb82c0::Forward() { return leaf_target(this); }
