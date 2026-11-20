// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf624e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf624e0 LeafForwardf624e0::Forward
#include "LeafForwardf624e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf624e0::Forward() { return leaf_target(this); }
