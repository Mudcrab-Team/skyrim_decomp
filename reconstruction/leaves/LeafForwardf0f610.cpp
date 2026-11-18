// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf0f610, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf0f610 LeafForwardf0f610::Forward
#include "LeafForwardf0f610.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf0f610::Forward() { return leaf_target(this); }
