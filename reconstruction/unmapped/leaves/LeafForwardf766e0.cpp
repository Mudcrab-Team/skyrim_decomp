// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf766e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf766e0 LeafForwardf766e0::Forward
#include "LeafForwardf766e0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf766e0::Forward() { return leaf_target(this); }
