// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd77d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd77d0 LeafForwardbd77d0::Forward
#include "LeafForwardbd77d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd77d0::Forward() { return leaf_target(this); }
