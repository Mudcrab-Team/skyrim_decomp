// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1bc60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1bc60 LeafForwardf1bc60::Forward
#include "LeafForwardf1bc60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1bc60::Forward() { return leaf_target(this); }
