// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa60d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa60d0 LeafForwardfa60d0::Forward
#include "LeafForwardfa60d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa60d0::Forward() { return leaf_target(this); }
