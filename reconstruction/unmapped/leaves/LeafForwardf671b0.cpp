// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf671b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf671b0 LeafForwardf671b0::Forward
#include "LeafForwardf671b0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf671b0::Forward() { return leaf_target(this); }
