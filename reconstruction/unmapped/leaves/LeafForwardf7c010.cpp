// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7c010, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7c010 LeafForwardf7c010::Forward
#include "LeafForwardf7c010.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7c010::Forward() { return leaf_target(this); }
