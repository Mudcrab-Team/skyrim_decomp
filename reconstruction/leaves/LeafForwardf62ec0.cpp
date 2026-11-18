// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf62ec0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf62ec0 LeafForwardf62ec0::Forward
#include "LeafForwardf62ec0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf62ec0::Forward() { return leaf_target(this); }
