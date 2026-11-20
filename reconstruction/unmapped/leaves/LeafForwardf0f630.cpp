// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f630 LeafForwardf0f630::Forward
#include "LeafForwardf0f630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f630::Forward() { return leaf_target(this); }
