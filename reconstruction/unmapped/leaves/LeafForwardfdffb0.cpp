// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfdffb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfdffb0 LeafForwardfdffb0::Forward
#include "LeafForwardfdffb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfdffb0::Forward() { return leaf_target(this); }
