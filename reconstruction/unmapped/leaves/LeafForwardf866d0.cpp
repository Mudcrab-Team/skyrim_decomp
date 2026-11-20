// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf866d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf866d0 LeafForwardf866d0::Forward
#include "LeafForwardf866d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf866d0::Forward() { return leaf_target(this); }
