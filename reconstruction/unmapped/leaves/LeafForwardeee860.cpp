// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeee860, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeee860 LeafForwardeee860::Forward
#include "LeafForwardeee860.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeee860::Forward() { return leaf_target(this); }
