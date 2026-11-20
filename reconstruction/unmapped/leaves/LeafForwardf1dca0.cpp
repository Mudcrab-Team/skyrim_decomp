// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1dca0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1dca0 LeafForwardf1dca0::Forward
#include "LeafForwardf1dca0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1dca0::Forward() { return leaf_target(this); }
