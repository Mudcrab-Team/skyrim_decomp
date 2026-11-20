// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6be0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6be0 LeafForwardff6be0::Forward
#include "LeafForwardff6be0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6be0::Forward() { return leaf_target(this); }
