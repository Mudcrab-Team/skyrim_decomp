// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf11bc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf11bc0 LeafForwardf11bc0::Forward
#include "LeafForwardf11bc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf11bc0::Forward() { return leaf_target(this); }
