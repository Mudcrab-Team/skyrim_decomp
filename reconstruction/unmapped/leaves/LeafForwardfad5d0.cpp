// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfad5d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfad5d0 LeafForwardfad5d0::Forward
#include "LeafForwardfad5d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfad5d0::Forward() { return leaf_target(this); }
