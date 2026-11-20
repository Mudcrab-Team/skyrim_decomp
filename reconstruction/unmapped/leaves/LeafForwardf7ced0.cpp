// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7ced0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7ced0 LeafForwardf7ced0::Forward
#include "LeafForwardf7ced0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7ced0::Forward() { return leaf_target(this); }
