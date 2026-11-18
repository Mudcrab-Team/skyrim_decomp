// Source exposure: binary-analysis; no external implementation reused.
// LeafForward94d630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x94d630 LeafForward94d630::Forward
#include "LeafForward94d630.h"
extern "C" void* leaf_target(void*);
void* LeafForward94d630::Forward() { return leaf_target(this); }
