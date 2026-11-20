// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf11400, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf11400 LeafForwardf11400::Forward
#include "LeafForwardf11400.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf11400::Forward() { return leaf_target(this); }
