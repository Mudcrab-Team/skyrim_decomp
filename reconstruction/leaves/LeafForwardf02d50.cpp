// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf02d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf02d50 LeafForwardf02d50::Forward
#include "LeafForwardf02d50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf02d50::Forward() { return leaf_target(this); }
