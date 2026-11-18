// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83ceb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83ceb0 LeafForward83ceb0::Forward
#include "LeafForward83ceb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward83ceb0::Forward() { return leaf_target(this); }
