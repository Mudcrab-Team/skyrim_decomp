// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf814a0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf814a0 LeafForwardf814a0::Forward
#include "LeafForwardf814a0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf814a0::Forward() { return leaf_target(this); }
