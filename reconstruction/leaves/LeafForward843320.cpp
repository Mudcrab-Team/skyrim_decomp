// Source exposure: binary-analysis; no external implementation reused.
// LeafForward843320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x843320 LeafForward843320::Forward
#include "LeafForward843320.h"
extern "C" void* leaf_target(void*);
void* LeafForward843320::Forward() { return leaf_target(this); }
