// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4f9430, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4f9430 LeafForward4f9430::Forward
#include "LeafForward4f9430.h"
extern "C" void* leaf_target(void*);
void* LeafForward4f9430::Forward() { return leaf_target(this); }
