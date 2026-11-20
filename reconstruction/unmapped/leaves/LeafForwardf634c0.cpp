// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf634c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf634c0 LeafForwardf634c0::Forward
#include "LeafForwardf634c0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf634c0::Forward() { return leaf_target(this); }
