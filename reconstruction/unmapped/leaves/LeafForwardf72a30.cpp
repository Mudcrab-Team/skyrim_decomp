// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf72a30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf72a30 LeafForwardf72a30::Forward
#include "LeafForwardf72a30.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf72a30::Forward() { return leaf_target(this); }
