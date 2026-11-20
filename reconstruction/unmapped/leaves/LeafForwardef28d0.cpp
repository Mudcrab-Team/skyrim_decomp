// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef28d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef28d0 LeafForwardef28d0::Forward
#include "LeafForwardef28d0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef28d0::Forward() { return leaf_target(this); }
