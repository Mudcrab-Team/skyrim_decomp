// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardec7ee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xec7ee0 LeafForwardec7ee0::Forward
#include "LeafForwardec7ee0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardec7ee0::Forward() { return leaf_target(this); }
