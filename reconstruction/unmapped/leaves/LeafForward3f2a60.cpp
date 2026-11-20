// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3f2a60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3f2a60 LeafForward3f2a60::Forward
#include "LeafForward3f2a60.h"
extern "C" void* leaf_target(void*);
void* LeafForward3f2a60::Forward() { return leaf_target(this); }
