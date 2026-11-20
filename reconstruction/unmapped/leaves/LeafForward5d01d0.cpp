// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5d01d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5d01d0 LeafForward5d01d0::Forward
#include "LeafForward5d01d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5d01d0::Forward() { return leaf_target(this); }
