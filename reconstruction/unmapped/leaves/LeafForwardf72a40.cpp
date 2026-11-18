// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf72a40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf72a40 LeafForwardf72a40::Forward
#include "LeafForwardf72a40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf72a40::Forward() { return leaf_target(this); }
