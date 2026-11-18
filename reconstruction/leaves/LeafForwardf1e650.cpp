// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1e650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1e650 LeafForwardf1e650::Forward
#include "LeafForwardf1e650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1e650::Forward() { return leaf_target(this); }
