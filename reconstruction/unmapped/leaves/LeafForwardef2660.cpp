// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardef2660, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xef2660 LeafForwardef2660::Forward
#include "LeafForwardef2660.h"
extern "C" void* leaf_target(void*);
void* LeafForwardef2660::Forward() { return leaf_target(this); }
