// Source exposure: binary-analysis; no external implementation reused.
// LeafForward205bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x205bb0 LeafForward205bb0::Forward
#include "LeafForward205bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward205bb0::Forward() { return leaf_target(this); }
