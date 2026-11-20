// Source exposure: binary-analysis; no external implementation reused.
// LeafForward108c5f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x108c5f0 LeafForward108c5f0::Forward
#include "LeafForward108c5f0.h"
extern "C" void* leaf_target(void*);
void* LeafForward108c5f0::Forward() { return leaf_target(this); }
