// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcf27a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcf27a0 LeafForwardcf27a0::Forward
#include "LeafForwardcf27a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcf27a0::Forward() { return leaf_target(this); }
