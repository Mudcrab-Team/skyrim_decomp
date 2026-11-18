// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf19470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf19470 LeafForwardf19470::Forward
#include "LeafForwardf19470.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf19470::Forward() { return leaf_target(this); }
