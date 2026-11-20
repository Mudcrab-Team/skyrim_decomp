// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardab3670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xab3670 LeafForwardab3670::Forward
#include "LeafForwardab3670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardab3670::Forward() { return leaf_target(this); }
