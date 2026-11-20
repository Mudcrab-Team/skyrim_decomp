// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf07020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf07020 LeafForwardf07020::Forward
#include "LeafForwardf07020.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf07020::Forward() { return leaf_target(this); }
