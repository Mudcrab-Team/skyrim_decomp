// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf39af0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf39af0 LeafForwardf39af0::Forward
#include "LeafForwardf39af0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf39af0::Forward() { return leaf_target(this); }
