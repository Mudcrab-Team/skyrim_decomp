// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1ed60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1ed60 LeafForwardf1ed60::Forward
#include "LeafForwardf1ed60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1ed60::Forward() { return leaf_target(this); }
