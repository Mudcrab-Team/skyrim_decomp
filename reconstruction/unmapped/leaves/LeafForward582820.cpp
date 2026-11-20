// Source exposure: binary-analysis; no external implementation reused.
// LeafForward582820, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x582820 LeafForward582820::Forward
#include "LeafForward582820.h"
extern "C" void* leaf_target(void*);
void* LeafForward582820::Forward() { return leaf_target(this); }
