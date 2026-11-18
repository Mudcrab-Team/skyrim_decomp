// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf39ae0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf39ae0 LeafForwardf39ae0::Forward
#include "LeafForwardf39ae0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf39ae0::Forward() { return leaf_target(this); }
