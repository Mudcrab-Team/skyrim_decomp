// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1481fa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1481fa0 LeafForward1481fa0::Forward
#include "LeafForward1481fa0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1481fa0::Forward() { return leaf_target(this); }
