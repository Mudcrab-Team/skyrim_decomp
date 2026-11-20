// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa26e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa26e0 LeafForwardfa26e0::Forward
#include "LeafForwardfa26e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa26e0::Forward() { return leaf_target(this); }
