// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf7b180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf7b180 LeafForwardf7b180::Forward
#include "LeafForwardf7b180.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf7b180::Forward() { return leaf_target(this); }
