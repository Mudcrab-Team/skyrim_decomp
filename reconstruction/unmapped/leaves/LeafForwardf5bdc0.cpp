// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf5bdc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf5bdc0 LeafForwardf5bdc0::Forward
#include "LeafForwardf5bdc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf5bdc0::Forward() { return leaf_target(this); }
