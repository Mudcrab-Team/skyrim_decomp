// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardaf22b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xaf22b0 LeafForwardaf22b0::Forward
#include "LeafForwardaf22b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardaf22b0::Forward() { return leaf_target(this); }
