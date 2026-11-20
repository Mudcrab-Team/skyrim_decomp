// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf69630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf69630 LeafForwardf69630::Forward
#include "LeafForwardf69630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf69630::Forward() { return leaf_target(this); }
