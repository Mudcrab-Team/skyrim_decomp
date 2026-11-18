// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf86080, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf86080 LeafForwardf86080::Forward
#include "LeafForwardf86080.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf86080::Forward() { return leaf_target(this); }
