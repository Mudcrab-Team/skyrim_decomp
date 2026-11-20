// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa09e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa09e0 LeafForwardfa09e0::Forward
#include "LeafForwardfa09e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa09e0::Forward() { return leaf_target(this); }
