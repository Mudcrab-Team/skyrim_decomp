// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8b7d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8b7d50 LeafForward8b7d50::Forward
#include "LeafForward8b7d50.h"
extern "C" void* leaf_target(void*);
void* LeafForward8b7d50::Forward() { return leaf_target(this); }
