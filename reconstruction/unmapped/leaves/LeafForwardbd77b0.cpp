// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd77b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd77b0 LeafForwardbd77b0::Forward
#include "LeafForwardbd77b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd77b0::Forward() { return leaf_target(this); }
