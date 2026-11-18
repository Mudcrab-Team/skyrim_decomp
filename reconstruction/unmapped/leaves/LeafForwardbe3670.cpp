// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbe3670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbe3670 LeafForwardbe3670::Forward
#include "LeafForwardbe3670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbe3670::Forward() { return leaf_target(this); }
