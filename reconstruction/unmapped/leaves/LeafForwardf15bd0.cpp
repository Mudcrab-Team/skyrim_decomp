// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf15bd0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf15bd0 LeafForwardf15bd0::Forward
#include "LeafForwardf15bd0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf15bd0::Forward() { return leaf_target(this); }
