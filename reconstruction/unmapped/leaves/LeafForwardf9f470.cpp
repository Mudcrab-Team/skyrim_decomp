// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf9f470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf9f470 LeafForwardf9f470::Forward
#include "LeafForwardf9f470.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf9f470::Forward() { return leaf_target(this); }
