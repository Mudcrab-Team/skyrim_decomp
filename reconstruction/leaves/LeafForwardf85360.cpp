// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85360, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85360 LeafForwardf85360::Forward
#include "LeafForwardf85360.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85360::Forward() { return leaf_target(this); }
