// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf19490, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf19490 LeafForwardf19490::Forward
#include "LeafForwardf19490.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf19490::Forward() { return leaf_target(this); }
