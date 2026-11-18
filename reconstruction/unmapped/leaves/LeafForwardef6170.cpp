// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef6170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef6170 LeafForwardef6170::Forward
#include "LeafForwardef6170.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef6170::Forward() { return leaf_target(this); }
