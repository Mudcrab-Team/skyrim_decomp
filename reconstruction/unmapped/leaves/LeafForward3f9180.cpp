// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3f9180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3f9180 LeafForward3f9180::Forward
#include "LeafForward3f9180.h"
extern "C" void* leaf_target(void*);
void* LeafForward3f9180::Forward() { return leaf_target(this); }
