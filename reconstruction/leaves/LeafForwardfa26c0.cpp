// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfa26c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfa26c0 LeafForwardfa26c0::Forward
#include "LeafForwardfa26c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfa26c0::Forward() { return leaf_target(this); }
