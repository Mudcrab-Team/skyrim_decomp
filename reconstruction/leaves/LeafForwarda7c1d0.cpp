// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda7c1d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa7c1d0 LeafForwarda7c1d0::Forward
#include "LeafForwarda7c1d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda7c1d0::Forward() { return leaf_target(this); }
