// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78b80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78b80 LeafForwardf78b80::Forward
#include "LeafForwardf78b80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78b80::Forward() { return leaf_target(this); }
