// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf6cbf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf6cbf0 LeafForwardf6cbf0::Forward
#include "LeafForwardf6cbf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf6cbf0::Forward() { return leaf_target(this); }
