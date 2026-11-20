// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69650 LeafForwardf69650::Forward
#include "LeafForwardf69650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69650::Forward() { return leaf_target(this); }
