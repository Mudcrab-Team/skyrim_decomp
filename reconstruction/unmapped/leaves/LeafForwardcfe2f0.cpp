// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardcfe2f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xcfe2f0 LeafForwardcfe2f0::Forward
#include "LeafForwardcfe2f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardcfe2f0::Forward() { return leaf_target(this); }
