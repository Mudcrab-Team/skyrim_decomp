// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1000fa0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1000fa0 LeafForward1000fa0::Forward
#include "LeafForward1000fa0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1000fa0::Forward() { return leaf_target(this); }
