// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8eac70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8eac70 LeafForward8eac70::Forward
#include "LeafForward8eac70.h"
extern "C" void* leaf_target(void*);
void* LeafForward8eac70::Forward() { return leaf_target(this); }
