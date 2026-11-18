// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa09f0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa09f0 LeafForwardfa09f0::Forward
#include "LeafForwardfa09f0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa09f0::Forward() { return leaf_target(this); }
