// Source exposure: binary-analysis; no external implementation reused.
// LeafForward6e0da0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x6e0da0 LeafForward6e0da0::Forward
#include "LeafForward6e0da0.h"
extern "C" void* leaf_target(void*);
void* LeafForward6e0da0::Forward() { return leaf_target(this); }
