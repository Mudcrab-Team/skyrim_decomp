// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7df740, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7df740 LeafForward7df740::Forward
#include "LeafForward7df740.h"
extern "C" void* leaf_target(void*);
void* LeafForward7df740::Forward() { return leaf_target(this); }
