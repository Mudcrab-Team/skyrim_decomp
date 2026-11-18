// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8d5c40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8d5c40 LeafForward8d5c40::Forward
#include "LeafForward8d5c40.h"
extern "C" void* leaf_target(void*);
void* LeafForward8d5c40::Forward() { return leaf_target(this); }
