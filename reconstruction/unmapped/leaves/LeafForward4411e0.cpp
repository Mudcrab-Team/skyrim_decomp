// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4411e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4411e0 LeafForward4411e0::Forward
#include "LeafForward4411e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward4411e0::Forward() { return leaf_target(this); }
