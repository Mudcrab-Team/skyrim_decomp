// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8c0a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8c0a60 LeafForward8c0a60::Forward
#include "LeafForward8c0a60.h"
extern "C" void* leaf_target(void*);
void* LeafForward8c0a60::Forward() { return leaf_target(this); }
