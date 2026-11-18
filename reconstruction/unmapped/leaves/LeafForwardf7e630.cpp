// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7e630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7e630 LeafForwardf7e630::Forward
#include "LeafForwardf7e630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7e630::Forward() { return leaf_target(this); }
