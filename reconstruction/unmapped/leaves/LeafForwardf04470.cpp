// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf04470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf04470 LeafForwardf04470::Forward
#include "LeafForwardf04470.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf04470::Forward() { return leaf_target(this); }
