// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88450 LeafForwardf88450::Forward
#include "LeafForwardf88450.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88450::Forward() { return leaf_target(this); }
