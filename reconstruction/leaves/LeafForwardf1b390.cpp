// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1b390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1b390 LeafForwardf1b390::Forward
#include "LeafForwardf1b390.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1b390::Forward() { return leaf_target(this); }
