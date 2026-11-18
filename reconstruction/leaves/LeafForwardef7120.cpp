// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef7120, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef7120 LeafForwardef7120::Forward
#include "LeafForwardef7120.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef7120::Forward() { return leaf_target(this); }
