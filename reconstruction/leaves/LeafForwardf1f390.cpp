// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1f390, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1f390 LeafForwardf1f390::Forward
#include "LeafForwardf1f390.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1f390::Forward() { return leaf_target(this); }
