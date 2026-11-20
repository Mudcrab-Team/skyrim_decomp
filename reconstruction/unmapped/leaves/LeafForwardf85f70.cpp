// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85f70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85f70 LeafForwardf85f70::Forward
#include "LeafForwardf85f70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85f70::Forward() { return leaf_target(this); }
