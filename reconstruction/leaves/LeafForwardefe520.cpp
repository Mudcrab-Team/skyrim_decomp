// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardefe520, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xefe520 LeafForwardefe520::Forward
#include "LeafForwardefe520.h"
extern "C" void* leaf_target(void*);
void* LeafForwardefe520::Forward() { return leaf_target(this); }
