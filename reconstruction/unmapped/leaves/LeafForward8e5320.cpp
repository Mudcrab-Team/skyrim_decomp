// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8e5320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8e5320 LeafForward8e5320::Forward
#include "LeafForward8e5320.h"
extern "C" void* leaf_target(void*);
void* LeafForward8e5320::Forward() { return leaf_target(this); }
