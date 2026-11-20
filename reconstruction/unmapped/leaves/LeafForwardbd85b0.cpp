// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd85b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd85b0 LeafForwardbd85b0::Forward
#include "LeafForwardbd85b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd85b0::Forward() { return leaf_target(this); }
