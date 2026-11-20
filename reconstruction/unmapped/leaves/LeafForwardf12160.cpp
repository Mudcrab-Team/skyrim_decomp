// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf12160, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf12160 LeafForwardf12160::Forward
#include "LeafForwardf12160.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf12160::Forward() { return leaf_target(this); }
