// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf98760, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf98760 LeafForwardf98760::Forward
#include "LeafForwardf98760.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf98760::Forward() { return leaf_target(this); }
