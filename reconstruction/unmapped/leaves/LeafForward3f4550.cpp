// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3f4550, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3f4550 LeafForward3f4550::Forward
#include "LeafForward3f4550.h"
extern "C" void* leaf_target(void*);
void* LeafForward3f4550::Forward() { return leaf_target(this); }
