// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1e630, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1e630 LeafForwardf1e630::Forward
#include "LeafForwardf1e630.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1e630::Forward() { return leaf_target(this); }
