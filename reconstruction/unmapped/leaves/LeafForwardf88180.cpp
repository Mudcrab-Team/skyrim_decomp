// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf88180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf88180 LeafForwardf88180::Forward
#include "LeafForwardf88180.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf88180::Forward() { return leaf_target(this); }
