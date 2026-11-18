// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf17b80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf17b80 LeafForwardf17b80::Forward
#include "LeafForwardf17b80.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf17b80::Forward() { return leaf_target(this); }
