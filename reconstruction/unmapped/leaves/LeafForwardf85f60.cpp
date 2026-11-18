// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf85f60, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf85f60 LeafForwardf85f60::Forward
#include "LeafForwardf85f60.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf85f60::Forward() { return leaf_target(this); }
