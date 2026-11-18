// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf17b90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf17b90 LeafForwardf17b90::Forward
#include "LeafForwardf17b90.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf17b90::Forward() { return leaf_target(this); }
