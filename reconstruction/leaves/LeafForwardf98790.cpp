// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf98790, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf98790 LeafForwardf98790::Forward
#include "LeafForwardf98790.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf98790::Forward() { return leaf_target(this); }
