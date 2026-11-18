// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85f40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85f40 LeafForwardf85f40::Forward
#include "LeafForwardf85f40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85f40::Forward() { return leaf_target(this); }
