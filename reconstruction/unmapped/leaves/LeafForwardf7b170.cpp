// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7b170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7b170 LeafForwardf7b170::Forward
#include "LeafForwardf7b170.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7b170::Forward() { return leaf_target(this); }
