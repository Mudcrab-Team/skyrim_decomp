// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa46b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa46b0 LeafForwardfa46b0::Forward
#include "LeafForwardfa46b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa46b0::Forward() { return leaf_target(this); }
