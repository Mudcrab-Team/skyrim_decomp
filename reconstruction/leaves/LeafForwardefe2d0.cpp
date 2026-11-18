// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardefe2d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xefe2d0 LeafForwardefe2d0::Forward
#include "LeafForwardefe2d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardefe2d0::Forward() { return leaf_target(this); }
