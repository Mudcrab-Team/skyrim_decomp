// Source exposure: binary-analysis; no external implementation reused.
// LeafForward61b1a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x61b1a0 LeafForward61b1a0::Forward
#include "LeafForward61b1a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward61b1a0::Forward() { return leaf_target(this); }
