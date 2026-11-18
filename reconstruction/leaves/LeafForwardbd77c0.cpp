// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd77c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd77c0 LeafForwardbd77c0::Forward
#include "LeafForwardbd77c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd77c0::Forward() { return leaf_target(this); }
