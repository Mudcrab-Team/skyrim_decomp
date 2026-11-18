// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf17bc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf17bc0 LeafForwardf17bc0::Forward
#include "LeafForwardf17bc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf17bc0::Forward() { return leaf_target(this); }
