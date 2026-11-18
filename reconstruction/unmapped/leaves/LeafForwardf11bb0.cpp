// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf11bb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf11bb0 LeafForwardf11bb0::Forward
#include "LeafForwardf11bb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf11bb0::Forward() { return leaf_target(this); }
