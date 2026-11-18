// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf78b90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf78b90 LeafForwardf78b90::Forward
#include "LeafForwardf78b90.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf78b90::Forward() { return leaf_target(this); }
