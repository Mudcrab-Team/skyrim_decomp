// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf987b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf987b0 LeafForwardf987b0::Forward
#include "LeafForwardf987b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf987b0::Forward() { return leaf_target(this); }
