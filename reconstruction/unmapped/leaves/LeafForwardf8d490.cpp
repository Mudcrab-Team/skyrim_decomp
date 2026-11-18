// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf8d490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf8d490 LeafForwardf8d490::Forward
#include "LeafForwardf8d490.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf8d490::Forward() { return leaf_target(this); }
