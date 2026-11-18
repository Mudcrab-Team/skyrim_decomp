// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf05370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf05370 LeafForwardf05370::Forward
#include "LeafForwardf05370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf05370::Forward() { return leaf_target(this); }
