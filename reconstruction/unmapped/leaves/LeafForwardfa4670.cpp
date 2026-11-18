// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa4670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa4670 LeafForwardfa4670::Forward
#include "LeafForwardfa4670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa4670::Forward() { return leaf_target(this); }
