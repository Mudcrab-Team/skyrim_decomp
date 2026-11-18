// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfff710, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfff710 LeafForwardfff710::Forward
#include "LeafForwardfff710.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfff710::Forward() { return leaf_target(this); }
