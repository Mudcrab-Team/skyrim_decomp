// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa65b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa65b0 LeafForwardfa65b0::Forward
#include "LeafForwardfa65b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa65b0::Forward() { return leaf_target(this); }
