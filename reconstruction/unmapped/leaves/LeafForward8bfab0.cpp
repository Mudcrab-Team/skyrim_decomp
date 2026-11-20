// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8bfab0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8bfab0 LeafForward8bfab0::Forward
#include "LeafForward8bfab0.h"
extern "C" void* leaf_target(void*);
void* LeafForward8bfab0::Forward() { return leaf_target(this); }
