// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardab27d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xab27d0 LeafForwardab27d0::Forward
#include "LeafForwardab27d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardab27d0::Forward() { return leaf_target(this); }
