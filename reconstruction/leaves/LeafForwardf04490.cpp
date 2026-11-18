// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf04490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf04490 LeafForwardf04490::Forward
#include "LeafForwardf04490.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf04490::Forward() { return leaf_target(this); }
