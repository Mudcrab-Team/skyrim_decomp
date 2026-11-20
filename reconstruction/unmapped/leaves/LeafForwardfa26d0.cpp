// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa26d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa26d0 LeafForwardfa26d0::Forward
#include "LeafForwardfa26d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa26d0::Forward() { return leaf_target(this); }
