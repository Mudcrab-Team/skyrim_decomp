// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1eec0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1eec0 LeafForwardf1eec0::Forward
#include "LeafForwardf1eec0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1eec0::Forward() { return leaf_target(this); }
