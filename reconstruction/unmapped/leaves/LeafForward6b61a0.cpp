// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6b61a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6b61a0 LeafForward6b61a0::Forward
#include "LeafForward6b61a0.h"
extern "C" void* leaf_target(void*);
void* LeafForward6b61a0::Forward() { return leaf_target(this); }
