// Source exposure: binary-analysis; no external implementation reused.
// LeafForward786c40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x786c40 LeafForward786c40::Forward
#include "LeafForward786c40.h"
extern "C" void* leaf_target(void*);
void* LeafForward786c40::Forward() { return leaf_target(this); }
