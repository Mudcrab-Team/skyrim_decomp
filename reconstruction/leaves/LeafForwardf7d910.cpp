// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7d910, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7d910 LeafForwardf7d910::Forward
#include "LeafForwardf7d910.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7d910::Forward() { return leaf_target(this); }
