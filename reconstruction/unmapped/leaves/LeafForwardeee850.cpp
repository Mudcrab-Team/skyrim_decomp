// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeee850, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeee850 LeafForwardeee850::Forward
#include "LeafForwardeee850.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeee850::Forward() { return leaf_target(this); }
