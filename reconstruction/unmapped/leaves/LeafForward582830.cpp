// Source exposure: binary-analysis; no external implementation reused.
// LeafForward582830, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x582830 LeafForward582830::Forward
#include "LeafForward582830.h"
extern "C" void* leaf_target(void*);
void* LeafForward582830::Forward() { return leaf_target(this); }
