// Source exposure: binary-analysis; no external implementation reused.
// LeafForward843a70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x843a70 LeafForward843a70::Forward
#include "LeafForward843a70.h"
extern "C" void* leaf_target(void*);
void* LeafForward843a70::Forward() { return leaf_target(this); }
