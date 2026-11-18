// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf02d40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf02d40 LeafForwardf02d40::Forward
#include "LeafForwardf02d40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf02d40::Forward() { return leaf_target(this); }
