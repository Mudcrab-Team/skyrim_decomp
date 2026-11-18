// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf89540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf89540 LeafForwardf89540::Forward
#include "LeafForwardf89540.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf89540::Forward() { return leaf_target(this); }
