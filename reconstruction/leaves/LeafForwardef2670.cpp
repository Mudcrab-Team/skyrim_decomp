// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef2670, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef2670 LeafForwardef2670::Forward
#include "LeafForwardef2670.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef2670::Forward() { return leaf_target(this); }
