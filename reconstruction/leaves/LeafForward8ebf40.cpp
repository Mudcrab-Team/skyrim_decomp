// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8ebf40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8ebf40 LeafForward8ebf40::Forward
#include "LeafForward8ebf40.h"
extern "C" void* leaf_target(void*);
void* LeafForward8ebf40::Forward() { return leaf_target(this); }
