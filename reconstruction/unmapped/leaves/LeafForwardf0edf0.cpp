// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0edf0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0edf0 LeafForwardf0edf0::Forward
#include "LeafForwardf0edf0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0edf0::Forward() { return leaf_target(this); }
