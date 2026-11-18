// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardff6c20, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xff6c20 LeafForwardff6c20::Forward
#include "LeafForwardff6c20.h"
extern "C" void* leaf_target(void*);
void* LeafForwardff6c20::Forward() { return leaf_target(this); }
