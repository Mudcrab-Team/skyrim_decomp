// Source exposure: binary-analysis; no external implementation reused.
// LeafForward85e620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x85e620 LeafForward85e620::Forward
#include "LeafForward85e620.h"
extern "C" void* leaf_target(void*);
void* LeafForward85e620::Forward() { return leaf_target(this); }
