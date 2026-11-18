// Source exposure: binary-analysis; no external implementation reused.
// LeafForward151d6a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x151d6a0 LeafForward151d6a0::Forward
#include "LeafForward151d6a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward151d6a0::Forward() { return leaf_target(this); }
