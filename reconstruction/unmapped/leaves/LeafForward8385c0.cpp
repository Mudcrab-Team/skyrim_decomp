// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8385c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8385c0 LeafForward8385c0::Forward
#include "LeafForward8385c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8385c0::Forward() { return leaf_target(this); }
