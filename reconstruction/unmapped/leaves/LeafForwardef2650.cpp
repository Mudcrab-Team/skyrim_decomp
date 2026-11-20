// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef2650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef2650 LeafForwardef2650::Forward
#include "LeafForwardef2650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef2650::Forward() { return leaf_target(this); }
