// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef2680, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef2680 LeafForwardef2680::Forward
#include "LeafForwardef2680.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef2680::Forward() { return leaf_target(this); }
