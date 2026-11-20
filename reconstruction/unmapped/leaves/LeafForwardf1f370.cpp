// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1f370, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1f370 LeafForwardf1f370::Forward
#include "LeafForwardf1f370.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1f370::Forward() { return leaf_target(this); }
