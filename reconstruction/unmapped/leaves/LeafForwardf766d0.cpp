// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf766d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf766d0 LeafForwardf766d0::Forward
#include "LeafForwardf766d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf766d0::Forward() { return leaf_target(this); }
