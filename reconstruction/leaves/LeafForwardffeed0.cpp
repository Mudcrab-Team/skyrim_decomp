// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardffeed0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xffeed0 LeafForwardffeed0::Forward
#include "LeafForwardffeed0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardffeed0::Forward() { return leaf_target(this); }
