// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa60b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa60b0 LeafForwardfa60b0::Forward
#include "LeafForwardfa60b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa60b0::Forward() { return leaf_target(this); }
