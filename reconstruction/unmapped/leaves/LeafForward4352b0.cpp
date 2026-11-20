// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4352b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4352b0 LeafForward4352b0::Forward
#include "LeafForward4352b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward4352b0::Forward() { return leaf_target(this); }
