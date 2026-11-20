// Source exposure: binary-analysis; no external implementation reused.
// LeafForward8eb320, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x8eb320 LeafForward8eb320::Forward
#include "LeafForward8eb320.h"
extern "C" void* leaf_target(void*);
void* LeafForward8eb320::Forward() { return leaf_target(this); }
