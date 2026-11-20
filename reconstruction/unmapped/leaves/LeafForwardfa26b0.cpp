// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa26b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa26b0 LeafForwardfa26b0::Forward
#include "LeafForwardfa26b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa26b0::Forward() { return leaf_target(this); }
