// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14c67b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14c67b0 LeafForward14c67b0::Forward
#include "LeafForward14c67b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward14c67b0::Forward() { return leaf_target(this); }
